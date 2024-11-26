/* USER CODE BEGIN Includes */
#include "lcd.h"
#include <stdio.h>  // For sprintf and debugging
/* USER CODE END Includes */

/* USER CODE BEGIN PV */
char debugBuffer[100]; // Buffer for debug messages
/* USER CODE END PV */

/* USER CODE BEGIN 2 */
  // Debug: Initialization start
  sprintf(debugBuffer, "Initializing peripherals...\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)debugBuffer, strlen(debugBuffer), HAL_MAX_DELAY);

  Lcd_PortType ports[] = { GPIOC, GPIOB, GPIOA, GPIOA };
  Lcd_PinType pins[] = { GPIO_PIN_7, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_6 };
  Lcd_HandleTypeDef lcd;
  lcd = Lcd_create(ports, pins, GPIOB, GPIO_PIN_5, GPIOB, GPIO_PIN_4, LCD_4_BIT_MODE);

  // Debug: LCD initialized
  sprintf(debugBuffer, "LCD initialized successfully.\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)debugBuffer, strlen(debugBuffer), HAL_MAX_DELAY);

  Lcd_cursor(&lcd, 0, 1);
  Lcd_string(&lcd, "Osman");

  // Debug: Display initial message
  sprintf(debugBuffer, "Displayed 'Osman' on the LCD.\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)debugBuffer, strlen(debugBuffer), HAL_MAX_DELAY);

  for (int x = 1; x <= 200; x++) {
      Lcd_cursor(&lcd, 1, 7);
      Lcd_int(&lcd, x);

      // Debug: Updated counter on LCD
      sprintf(debugBuffer, "Counter value updated on LCD: %d\r\n", x);
      HAL_UART_Transmit(&huart1, (uint8_t *)debugBuffer, strlen(debugBuffer), HAL_MAX_DELAY);

      HAL_Delay(1000);
  }
/* USER CODE END 2 */

/* USER CODE BEGIN 4 */
// Example debug message in Error_Handler
void Error_Handler(void)
{
  sprintf(debugBuffer, "Error occurred! System halting.\r\n");
  HAL_UART_Transmit(&huart1, (uint8_t *)debugBuffer, strlen(debugBuffer), HAL_MAX_DELAY);

  __disable_irq();
  while (1)
  {
  }
}
/* USER CODE END 4 */
