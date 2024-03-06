// https://medium.com/a-42-journey/how-to-create-your-own-malloc-library-b86fedd39b96
#include "../include/malloc.h"

t_zoneMemoireType get_heap_group(size_t size)
{
    if (size <= (size_t)TINY_BLOCK_SIZE)
        return (TINY);
    else if (size <= (size_t)SMALL_BLOCK_SIZE)
        return (SMALL);
    return (LARGE);
}

void *start_malloc(size_t size)
{
    page_memory_t *heap;
    block_memory_t *block;
    void *res;

    if (!size)
        return (NULL);

    if ((block = try_fill_block(size)))
        return (BLOCK_SHIFT(block));

    res = Add_Empty_Block(heap, size);
    return res;
}

void *malloc(size_t size)
{
    void *res;

    res = start_malloc(size);

    return res;
}

int main()
{
    printf("======================= Ma Function ========================\n");
    void *fun;
    fun = malloc(12);
    return 0;
}