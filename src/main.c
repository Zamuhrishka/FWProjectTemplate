/*******************************************************************************
 *
 * @file    		main.c
 * @author  		Kovalchuk Alexander (roux@yandex.ru)
 * @brief   		Source files for application lavel.
 *
 ******************************************************************************/
//_____ I N C L U D E S _______________________________________________________
#include "imutex.h"
#include "custom_allocator.h"
//_____ C O N F I G U R A T I O N   B I T S ___________________________________
//_____ D E F I N I T I O N ___________________________________________________
//_____ F U N C T I O N   D E C L A R A T I O N _______________________________
//_____ V A R I A B L E   D E F I N I T I O N  ________________________________
//_____ S T A T I C   F U N C T I O N S ________________________________________

//_____ F U N C T I O N   D E F I N I T I O N   ________________________________
/**
 * @brief   This main function.
**/
int main (void)
{   
    while(1)
    {
      unit_t *pBlock = custom_alloc();
      custom_free(pBlock);
    }
}
