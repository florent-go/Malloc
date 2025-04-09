#include <../includes/malloc.h>

void        *large_alloc_memory(const size_t size)
{
    void	*res;

	if (g_data->ptr_large == NULL)
	{
		if (!(g_data->ptr_large = mmap(0, sizeof(t_page) + size,
						PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (NULL);
		fill_struct_alloc((t_page*)g_data->ptr_large, NULL, size);
		return (g_data->ptr_large);
	}
    res = g_data->ptr_large;
    while (((t_page*)res)->next)
		res = ((t_page*)res)->next;
	if (!(((t_page*)res)->next = mmap(0, sizeof(t_page) + size,
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	fill_struct_alloc(((t_page*)res)->next, res, size);
    return (((t_page*)res)->next);
}