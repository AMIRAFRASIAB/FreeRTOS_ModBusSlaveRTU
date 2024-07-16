
#include "main.h"
#include "stm32f4xx_it.h"

void NMI_Handler(void) {
  while (1) {
    __NOP();
  }

}

void HardFault_Handler(void) {
  __disable_irq();
  while (1) {
    __NOP();
  }
}

