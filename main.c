#include "./includes/malloc.h"

int		test_malloc_1(int nb_malloc, int size_start)
{
	char	*(s1[nb_malloc]);
	int		i;
	int		j;

	i = -1;
	while (++i < nb_malloc)
	{
		if (!(s1[i] = malloc(size_start + i)))
			return (0);
		j = -1;
		while (++j < size_start + i)
			s1[i][j] = 'a' + j % 26;
		s1[i][j] = '\0';
		if (ft_strlen(s1[i]) != (size_t)size_start + i)
		{
			printf("ERROR bad size %s %s %d\n", __func__, __FILE__, __LINE__);
			return (0);
		}
	}
	return (1);
}

int			test_malloc(void)
{
	printf("TEST MALLOC:\n");
	printf("\tTINY:\t");
	if (test_malloc_1(200, 0) == 0)
	{
		printf("ERROR\n");
		return (0);
	}
	printf("OK\n");
	printf("\tSMALL:\t");
	if (test_malloc_1(100, TINY_BLOCK_SIZE + 1) == 0)
	{
		printf("ERROR\n");
		return (0);
	}
	printf("OK\n");
	printf("\tLARGE:\t");
	if (test_malloc_1(100, SMALL_BLOCK_SIZE + 1) == 0)
	{
		printf("ERROR\n");
		return (0);
	}
	printf("OK\n");
	return (1);
}

int test_malloc_new_page()
{
	int 	nb_malloc = 2000;
	char	*(s1[nb_malloc]);
	int		i;
	int 	j;

	i = -1;
	while (++i < nb_malloc)
	{
		if (!(s1[i] = malloc(100)))
			return (0);
		j = -1;
		while (++j < 100)
			s1[i][j] = 'a' + j % 26;
		s1[i][j] = '\0';
		if (ft_strlen(s1[i]) != (size_t)100)
		{
			printf("ERROR bad size %s %s %d\n", __func__, __FILE__, __LINE__);
			return (0);
		}
	}
}


int			main(int ac, char **av)
{
	int		err;

	err = 1;
	(void)ac;
	(void)av;
	if (test_malloc_new_page() == 0) {ft_printf("ERROR malloc\n"); return (1);}
	// if (test_malloc() == 0) {ft_printf("ERROR malloc\n"); return (1);}
	// test_malloc_1(1, 1);
	show_alloc_mem();
	return (0);
}
