//_____ I N C L U D E S _______________________________________________________________________
#include "imutex.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

// #include "FreeRTOS.h"
// #include "semphr.h"
//_____ C O N F I G S  ________________________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________________________
//_____ M A C R O S ___________________________________________________________________________
//_____ V A R I A B L E S _____________________________________________________________________
// xSemaphoreHandle mutex;
//_____ P R I V A T E  F U N C T I O N ________________________________________________________
//_____ P U B L I C   F U N C T I O N _________________________________________________________
bool mutex_acquire(void)
{
    // return (xSemaphoreTake(mutex, portMAX_DELAY) == pdPASS) ? true : false;
    return true;
}

bool mutex_release(void)
{
    // return (xSemaphoreGive(mutex) == pdPASS) ? true : false;
    return true;
}