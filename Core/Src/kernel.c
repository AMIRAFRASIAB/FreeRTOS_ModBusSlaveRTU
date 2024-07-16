
#include "kernel.h"
#include "main.h"
#include "led.h"


static TaskHandle_t hTaskKernel = NULL;
static void __kernelService (void* const pvParameters);

bool kernel_init (void) {
  bool status = true;
  status = status && xTaskCreate(&__kernelService, "Kernel Task", 256, NULL, 1, &hTaskKernel) == pdTRUE;
  return status;
}

void __kernelService (void* const pvParameters) {
  led_init(500);
  while (1) {
    vTaskSuspend(NULL);
  }
}