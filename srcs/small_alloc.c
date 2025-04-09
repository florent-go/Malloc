#include <../includes/malloc.h>

static bool     init(t_pagetype type)
{
    if (type == TINY)
    {
        if (!(g_data->ptr_tiny =  mmap(0, TINY_HEAP_ALLOCATION_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1,0)))
            return false;
        fill_struct_alloc(g_data->ptr_tiny, NULL, TINY_HEAP_ALLOCATION_SIZE - sizeof(t_page));
        ((t_page*)g_data->ptr_tiny)->is_free = true;
        ((t_page*)g_data->ptr_tiny)->empty = true;
        g_data->total_size_tiny = TINY_HEAP_ALLOCATION_SIZE;
    }
    else if (type == SMALL)
    {
        if (!(g_data->ptr_small =  mmap(0, SMALL_HEAP_ALLOCATION_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1,0)))
            return false;
        fill_struct_alloc(g_data->ptr_small, NULL, SMALL_HEAP_ALLOCATION_SIZE - sizeof(t_page));
        ((t_page*)g_data->ptr_small)->is_free = true;
        ((t_page*)g_data->ptr_small)->empty = true;
        g_data->total_size_small = SMALL_HEAP_ALLOCATION_SIZE;
    }
    return true;
}

static bool	alloc_new_slot(void *ptr, t_pagetype type)
{
	void	*new;

	if (type == TINY)
	{
		if (!(new = mmap(0, TINY_HEAP_ALLOCATION_SIZE, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (false);
		g_data->total_size_tiny += TINY_HEAP_ALLOCATION_SIZE;
	}
	else
	{
		if (!(new = mmap(0, SMALL_HEAP_ALLOCATION_SIZE, PROT_READ | PROT_WRITE,
						MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (false);
		g_data->total_size_small += SMALL_HEAP_ALLOCATION_SIZE;
	}
	((t_page*)ptr)->next = new;
    if (type == TINY)
        fill_struct_alloc((t_page*)new, ptr,  TINY_HEAP_ALLOCATION_SIZE);
    else
        fill_struct_alloc((t_page*)new, ptr,  SMALL_HEAP_ALLOCATION_SIZE);
	((t_page*)new)->is_free = true;
	((t_page*)new)->empty = true;
	return (true);
}

static void    *small_alloc_memory2(size_t size, t_pagetype type, void *ptr)
{
	t_page	*tmp;

	if (((t_page*)ptr)->is_free == true &&
			((t_page*)ptr)->size > size + (sizeof(t_page) * 2))
	{
		((t_page*)ptr)->is_free = false;
		tmp = ((t_page*)ptr)->next;
		((t_page*)ptr)->next = ptr + sizeof(t_page) + size;
		fill_struct_alloc(((t_page*)ptr)->next, ptr, 
                ((t_page*)ptr)->size - size - sizeof(t_page));
		((t_page*)ptr)->size = size;
		((t_page*)ptr)->next->is_free = true;
		((t_page*)ptr)->next->next = tmp;
		if (tmp)
			tmp->prev = ((t_page*)ptr)->next;
		return (ptr);
	}
	if (alloc_new_slot(ptr, type) == false)
		return (NULL);
	return (small_alloc_memory(size, type));
}

void    *small_alloc_memory(size_t aligned_size, t_pagetype type)
{
    void    *res;
    size_t  size;
    size_t  total_size;

    if (type == TINY && g_data->ptr_tiny == NULL)
        if (init(type) == false)
            return (NULL);
    else if (type == SMALL && g_data->ptr_small == NULL)
        if (init(type) == false)
            return  NULL;
    
    if (type == TINY)
    {
        res = g_data->ptr_tiny;
        total_size = g_data->total_size_tiny;
    }
    else if (type == SMALL)
    {
        res = g_data->ptr_small;
        total_size = g_data->total_size_small;
    }
    size = 0;
    while(((t_page *)res)->next)
    {
        if (((t_page*)res)->is_free == true && ((t_page *)res)->size > size + (sizeof(t_page) * 2))
            break;
        size += ((t_page*)res)->size + sizeof(t_page);
        res = ((t_page*)res)->next;
    }
    return small_alloc_memory2(size, type, res);
}