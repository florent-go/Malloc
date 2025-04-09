#include <../includes/malloc.h>

static int	print_alloc(void *ptr, size_t *total_octet)
{
	int		i;
	size_t	nb_octet;

	nb_octet = 0;
	i = 0;
	while (ptr)
	{
		if (((t_page*)ptr)->is_free == false)
		{
			i++;
			nb_octet += ((t_page*)ptr)->aligned_size;
			printf("\t%p - %p : %zu octets\n",
					ptr + sizeof(t_page),
					ptr + sizeof(t_page) + ((t_page*)ptr)->aligned_size,
					((t_page*)ptr)->aligned_size);
		}
		ptr = ((t_page*)ptr)->next;
	}
	printf("\ttotal: %d block (%zu octets)\n", i, nb_octet);
	*total_octet += nb_octet;
	return (i);
}

void		show_alloc_mem(void)
{
	void	*ptr;
	int		total;
	size_t	total_octet;

	total_octet = 0;
	total = 0;
	if (!g_data)
		printf("total: %d block (%zu octets)\n", total, total_octet);
	printf("TINY: %p\n", g_data->ptr_tiny);
	ptr = g_data->ptr_tiny;
	total += print_alloc(ptr, &total_octet);
	printf("SMALL: %p\n", g_data->ptr_small);
	ptr = g_data->ptr_small;
	total += print_alloc(ptr, &total_octet);
	printf("LARGE: %p\n", g_data->ptr_large);
	ptr = g_data->ptr_large;
	total += print_alloc(ptr, &total_octet);
	printf("total: %d block (%zu octets)\n", total, total_octet);
}