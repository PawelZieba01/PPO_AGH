#include "Led_Lcd.h"

#define LED_NUMBER 4
#define LED_WIDTH 80
#define LED_HEIGHT 80
#define LED_X_POS 0
#define LED_Y_POS 0

#define LED_ON_COLOR LCD_COLOR_YELLOW
#define LED_OFF_COLOR LCD_COLOR_BLUE

LedLcd::LedLcd(void)
{
    BSP_LCD_SetFont(&Font24);
    
    LCD.Clear(LCD_COLOR_BLACK);
    LCD.SetBackColor(LCD_COLOR_BLACK);
}


void LedLcd::DrawLed(uint8_t RectIndex, uint32_t Color)
{
    LCD.SetTextColor(Color);
    LCD.FillRect(LED_X_POS, LED_Y_POS + (RectIndex*LED_HEIGHT), LED_WIDTH, LED_HEIGHT);

    LCD.SetTextColor(LCD_COLOR_GREEN);
    LCD.DrawRect(LED_X_POS, LED_Y_POS + (RectIndex*LED_HEIGHT), LED_WIDTH, LED_HEIGHT);

    LCD.SetTextColor(LCD_COLOR_WHITE);
    LCD.SetBackColor(LCD_COLOR_RED);
    LCD.DisplayChar(LED_X_POS, LED_Y_POS + (RectIndex*LED_HEIGHT), (RectIndex + '0'));
}

void LedLcd::On(uint8_t LedIndex)
{
    for(uint8_t LedCtr = 0 ; LedCtr < LED_NUMBER ; LedCtr++)
    {
        DrawLed(LedCtr, LED_OFF_COLOR);
    }

    if(LedIndex < LED_NUMBER)
    {
        DrawLed(LedIndex, LED_ON_COLOR);
    }
}
