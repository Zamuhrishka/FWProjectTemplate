// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com
/*******************************************************************************
 *
 * @file    		main.c
 * @author  		Kovalchuk Alexander (roux@yandex.ru)
 * @brief   		Source files for application lavel.
 *
 ******************************************************************************/
//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include "queue.h"
//_____ C O N F I G U R A T I O N   B I T S ___________________________________
//_____ D E F I N I T I O N ___________________________________________________
//_____ F U N C T I O N   D E C L A R A T I O N _______________________________
//_____ V A R I A B L E   D E F I N I T I O N  ________________________________
static queue_t* queue = NULL;
//_____ S T A T I C   F U N C T I O N S ________________________________________
//_____ F U N C T I O N   D E F I N I T I O N   ________________________________
/**
 * @brief   This main function.
**/
int main (void)
{  
    static const char *const FW_Date = __DATE__;
    static const char *const FW_Time = __TIME__;

    printf("Firmware date: %s, time: %s", FW_Date, FW_Time);

    queue = queue_create(10, sizeof(uint8_t));  

    while(1)
    {


    }
}
