#include "Led.h"
#include "LCD_DISCO_F429ZI.h"

#define LED_NUMBER 4
#define LED_WIDTH 80
#define LED_HEIGHT 80

#define LED_ON_COLOR LCD_COLOR_YELLOW
#define LED_OFF_COLOR LCD_COLOR_BLUE

extern LCD_DISCO_F429ZI LCD;

Led::Led(unsigned char ucColumn, unsigned char ucRow)
{
    this->ucColumn = ucColumn;
    this->ucRow = ucRow;

    BSP_LCD_SetFont(&Font24);
    
    LCD.Clear(LCD_COLOR_BLACK);
    LCD.SetBackColor(LCD_COLOR_BLACK);
}


void Led::Redraw(uint32_t Color)
{
    LCD.SetTextColor(Color);
    LCD.FillRect(ucColumn*LED_WIDTH, (ucRow*LED_HEIGHT), LED_WIDTH, LED_HEIGHT);

    LCD.SetTextColor(LCD_COLOR_GREEN);
    LCD.DrawRect(ucColumn*LED_WIDTH, (ucRow*LED_HEIGHT), LED_WIDTH, LED_HEIGHT);

    LCD.SetTextColor(LCD_COLOR_WHITE);
    LCD.SetBackColor(LCD_COLOR_RED);
    LCD.DisplayChar(ucColumn*LED_WIDTH, (ucRow*LED_HEIGHT), (ucRow + '0'));
}

void Led::On(void)
{
    Redraw(LED_ON_COLOR);
}

void Led::Off(void)
{
    Redraw(LED_OFF_COLOR);
}