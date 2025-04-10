#include "../includes/malloc.h"

t_pagetype      get_type(size_t size)
{
    if (size <= (size_t)TINY_BLOCK_SIZE)
        return (TINY);
    else if (size <= (size_t)SMALL_BLOCK_SIZE)
        return (SMALL);
    return (LARGE);
}

void            fill_struct_alloc(t_page *heap, t_page *prev, size_t size)
{
    heap->empty = false;
    heap->prev = prev;
    heap->next = NULL;
    heap->is_free = false;
    heap->size = size;
    heap->aligned_size = size;
}
