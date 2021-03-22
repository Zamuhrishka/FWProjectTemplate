//_____ I N C L U D E S _______________________________________________________________________
#include "custom_allocator.h"
#include "imutex.h"

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
//_____ C O N F I G S  ________________________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________________________
#ifndef POOL_SIZE_IN_UNITS
    #error "Please define POOL_SIZE_IN_UNITS"
#endif

#ifndef UNITS_IN_BLOCK
    #error "Please define UNITS_IN_BLOCK"
#endif

/**
 * \brief   Internal struct for allocator
 */
#pragma pack(push,1)
typedef struct tagBlock 
{
    bool busy;
    unit_t block[UNITS_IN_BLOCK];
}   Block_t;
#pragma pack(pop)
//_____ M A C R O S ___________________________________________________________________________
//_____ V A R I A B L E S _____________________________________________________________________
static Block_t pool[POOL_SIZE_IN_UNITS][1] = {{0}};
//_____ P R I V A T E  F U N C T I O N ________________________________________________________
//_____ P U B L I C   F U N C T I O N _________________________________________________________
/**
* This functions allocate block of data UNITS_IN_BLOCK size.
*
* Public function defined in custom_allocator.h
*/
unit_t *custom_alloc(void)
{
    unit_t *pBlock = NULL;

    while(!mutex_acquire()) {};

    for(size_t i = 0; i < POOL_SIZE_IN_UNITS; i++)
    {
        if(!pool[i][0].busy)
        {
            pool[i][0].busy = true;
            pBlock = &pool[i][0].block;
        }
    }

    mutex_release();

    return pBlock;
}

/**
* This functions deallocate block of data.
*
* Public function defined in custom_allocator.h
*/
void custom_free(unit_t *pBlock)
{
    bool* pBusy = NULL;
    if(pBlock != NULL)
    {
        pBusy = (bool*)(pBlock - sizeof(pBusy));

        while(!mutex_acquire()){};
        *pBusy = false;
    }
}