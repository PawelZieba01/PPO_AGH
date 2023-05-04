#include "mbed.h"
#include "TS_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"

#define BTN_WIDTH 80
#define BTN_HEIGHT 80
#define FIRST_BTN_X_POS 0
#define FIRST_BTN_Y_POS 0
#define BTN_NUM 4

#define LED_ON_COLOR LCD_COLOR_YELLOW
#define LED_OFF_COLOR LCD_COLOR_BLUE

LCD_DISCO_F429ZI lcd;
TS_DISCO_F429ZI ts;


void DrawRect(uint8_t RectIndex, uint32_t Color)
{
    lcd.SetTextColor(Color);
    lcd.FillRect(FIRST_BTN_X_POS, FIRST_BTN_Y_POS + (RectIndex*BTN_HEIGHT), BTN_WIDTH, BTN_HEIGHT);

    lcd.SetTextColor(LCD_COLOR_GREEN);
    lcd.DrawRect(FIRST_BTN_X_POS, FIRST_BTN_Y_POS + (RectIndex*BTN_HEIGHT), BTN_WIDTH, BTN_HEIGHT);

    lcd.SetTextColor(LCD_COLOR_WHITE);
    lcd.SetBackColor(LCD_COLOR_RED);
    lcd.DisplayChar(FIRST_BTN_X_POS, FIRST_BTN_Y_POS + (RectIndex*BTN_HEIGHT), (RectIndex + '0'));
}

void LedOn(uint8_t LedIndex)
{
    DrawRect(LedIndex, LED_ON_COLOR);
}

void LedOff(uint8_t LedIndex)
{
    DrawRect(LedIndex, LED_OFF_COLOR);
}



typedef enum eKeyboardState {RELEASED, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4} eKeyboardState;

eKeyboardState eKeyboardRead(void)
{
    TS_StateTypeDef TS_State;
    eKeyboardState KeyboardState;

    ts.GetState(&TS_State);
    if(TS_State.TouchDetected    &&    (TS_State.X >= FIRST_BTN_X_POS) && (TS_State.X < FIRST_BTN_X_POS + BTN_WIDTH))
    {
        uint8_t PressedKey = TS_State.Y / BTN_HEIGHT;
        switch(PressedKey)
        {
            case 0:
                KeyboardState = BUTTON_1;
                break;
            case 1:
                KeyboardState = BUTTON_2;
                break;
            case 2:
                KeyboardState = BUTTON_3;
                break;
            case 3:
                KeyboardState = BUTTON_4;
                break;
        }
    }
    else 
    {
        KeyboardState = RELEASED;
    }

    return KeyboardState;
}



int main()
{
    
    eKeyboardState KeyboardState; 

    BSP_LCD_SetFont(&Font24);
    ts.Init(lcd.GetXSize(), lcd.GetYSize());
  
    lcd.Clear(LCD_COLOR_BLACK);
    lcd.SetBackColor(LCD_COLOR_BLACK);

    
    while(1)
    {
        for(uint8_t LedIndex = 0; LedIndex < BTN_NUM ; LedIndex++)
        {
            LedOff(LedIndex);
        }

        switch(eKeyboardRead())
            {
                case BUTTON_1:
                    LedOn(0);
                    break;
                case BUTTON_2:
                    LedOn(1);
                    break;
                case BUTTON_3:
                    LedOn(2);
                    break;
                case BUTTON_4:
                    LedOn(3);
                    break;
                default:
                    break;
            }
        
        wait(0.1);
    }
}
