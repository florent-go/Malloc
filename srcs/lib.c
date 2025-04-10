#include "../includes/malloc.h"

void ft_itoa_base(size_t nb, char base, char lenght, bool prefixe)
{
    char *str;

    str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (nb/base)
        ft_itoa_base(nb/base, base,lenght-1, prefixe);
    else
    {
        if (prefixe)
            ft_putstr("0x");
        while(--lenght > 0)
        {
            ft_putstr("0");
        }
    }
    write(1, &str[nb % base], 1);
}