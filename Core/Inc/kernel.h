
#ifndef __KERNEL_H_INCLUDED__
#define __KERNEL_H_INCLUDED__


#ifdef __cplusplus
  extern "C"{
#endif  

#include <stdint.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"






bool kernel_init (void);

#ifdef __cplusplus
  };
#endif  
#endif //__KERNEL_H_INCLUDED__