#include "./includes/malloc.h"

void	ft_putnbr_hex(int octet, int rem) { char const *base = "0123456789abcdef"; if (rem > 1) ft_putnbr_hex(octet >> 4, rem - 1); write(1, base + (octet % 16), 1); } void	sp_putchar(unsigned char const *ptr) { char const c = *ptr; if (' ' <= c && c <= '~') write(1, ptr, 1); else write(1, ".", 1); } void	print_memory(const void *addr, size_t size) { size_t i; size_t a; unsigned char const *ptr = addr; i = 0; while (i < size) { a = 0; while (a < 16 && a + i < size) { ft_putnbr_hex(*(ptr + i + a), 2); if (a % 2) write(1, " ", 1); a++; } while (a < 16) { write(1, "  ", 2); if (a % 2) write(1, " ", 1); a++; } a = 0; while (a < 16 && a + i < size) { sp_putchar(ptr + a + i); a++; } write(1, "\n", 1); i += 16; } }


size_t		ft_strlen(const char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

#define NB_MALLOC 26
#define SIZE_1 51

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
			printf("Error bad size %s %s %d\n", __func__, __FILE__, __LINE__);
			return (0);
		}
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		err;

	err = 1;
	(void)ac;
	(void)av;
	void *ptr = malloc(20);
	// test_malloc_1(1, 1);

	show_alloc_mem();
	return (0);
}
