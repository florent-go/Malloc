#include "../includes/malloc.h"

t_data *g_data = NULL;

bool    init_struct()
{
    if (!(g_data = mmap(0, sizeof(t_data), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1,0)))
        return false;
    g_data->ptr_large = NULL;
    g_data->ptr_small = NULL; 
    g_data->ptr_tiny = NULL;
    return true;
}

void    *start_malloc(size_t size)
{
    void        *res;
    size_t      aligned_size;
    t_pagetype  type;

    if (g_data == NULL)
        if (init_struct() == false)
            return NULL;
    
    aligned_size = ((((size - 1) >> 3) << 3) + 8);
    type = get_type(aligned_size);
    if (type == LARGE)
        res = large_alloc_memory(aligned_size);
    else
        res = small_alloc_memory(aligned_size, type);
    ((t_page*)res)->aligned_size = aligned_size;
    return (res + sizeof(t_page));
}

void    *malloc(size_t size)
{
    void *res;
    res = start_malloc(size);
    return (res);
}

