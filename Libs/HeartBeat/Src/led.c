
#include "led.h"
#include "FreeRTOS.h"
#include "task.h"


static TaskHandle_t hTaskHeartBeat = NULL;
static void heartBeatService (void* const pvParameters);
static uint32_t __delay;

bool led_init (uint32_t delay) {
  __delay = delay;
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_13, LL_GPIO_MODE_OUTPUT);
  LL_GPIO_SetPinOutputType(GPIOC, LL_GPIO_PIN_13, LL_GPIO_OUTPUT_PUSHPULL);
  
  bool status = true;
  status = status && xTaskCreate(&heartBeatService, "LED_Task", 32, &__delay, 1, &hTaskHeartBeat) == pdTRUE;
  return status;
}


static void heartBeatService (void* const pvParameters) {
  while (1) {
    LL_GPIO_TogglePin(GPIOC, LL_GPIO_PIN_13);
    vTaskDelay(*(uint32_t*)pvParameters);
  }
}