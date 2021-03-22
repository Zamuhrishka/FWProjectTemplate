#ifndef CUSTOM_ALLOCATOR_H
#define CUSTOM_ALLOCATOR_H
//_____ I N C L U D E S _______________________________________________________________________
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
//_____ C O N F I G S__________________________________________________________________________
#define POOL_SIZE_IN_UNITS          10                                                          //< Size of memory pool
#define UNITS_IN_BLOCK              32                                                          //< Size of one allocated block in unit_t count
//_____ M A C R O S ___________________________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________________________
typedef uint8_t unit_t;
//_____ P U B L I C   F U N C T I O N _________________________________________________________
/** 
 * @brief   This functions allocate block of data UNITS_IN_BLOCK size.
 *
 * @param   none.
 *
 * @return  allocated block.
**/
unit_t *custom_alloc(void);

/** 
 * @brief   This functions deallocate block of data.
 *
 * @param   pBlock[in] - block of data which was allocated by custom_alloc function.
 *
 * @return  none.
**/
void custom_free(unit_t *pBlock);

#endif // CUSTOM_ALLOCATOR_H
