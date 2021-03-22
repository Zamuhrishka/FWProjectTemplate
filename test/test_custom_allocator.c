#include "unity.h"

#include "custom_allocator.h"

//mock
#include "mock_imutex.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Allocate(void)
{
    mutex_acquire_IgnoreAndReturn(true);
    mutex_release_IgnoreAndReturn(true);
    unit_t *pBlock = custom_alloc();
    TEST_ASSERT_NOT_NULL(pBlock);
    mutex_acquire_IgnoreAndReturn(true);
    mutex_release_IgnoreAndReturn(true);
    custom_free(pBlock);
}

void test_AllocateOverload(void)
{
    unit_t *blocks[POOL_SIZE_IN_UNITS] = {NULL};

    for(size_t i = 0; i < POOL_SIZE_IN_UNITS; i++)
    {
        mutex_acquire_IgnoreAndReturn(true);
        mutex_release_IgnoreAndReturn(true);
        blocks[i] = custom_alloc();        
    }

    mutex_acquire_IgnoreAndReturn(true);
    mutex_release_IgnoreAndReturn(true);
    unit_t *pBlock = custom_alloc();
    TEST_ASSERT_NULL(pBlock);

    for(size_t i = 0; i < POOL_SIZE_IN_UNITS; i++)
    {
        mutex_acquire_IgnoreAndReturn(true);
        mutex_release_IgnoreAndReturn(true);
        custom_free(blocks[i]);
    }
}