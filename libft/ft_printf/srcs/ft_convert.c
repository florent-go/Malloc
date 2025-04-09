/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:52:38 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/22 09:40:51 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_hexatoi(unsigned long long nbr, int base)
{
	char				*hexa_char;
	int					len;

	hexa_char = 0;
	len = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	len = ft_len2(nbr, base);
	if (!(hexa_char = malloc(sizeof(char) * (len + 1))))
		return (0);
	hexa_char[len] = '\0';
	len--;
	while (len >= 0)
	{
		if ((nbr % base) < 10)
			hexa_char[len] = (nbr % base) + '0';
		else
			hexa_char[len] = (nbr % base) + '7';
		nbr = nbr / base;
		len--;
	}
	return (hexa_char);
}

char	*ft_itoa_flag(int n, t_option option)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	if (sign == -1 && option.dot >= 0)
		len--;
	if (sign == -1 && option.dot < 0 && option.flag_zero == 1)
		len--;
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1 && option.dot < 0 && option.flag_zero == 0)
		c[0] = '-';
	return (c);
}

char	*ft_unsigned_itoa(int n)
{
	int		len;
	int		sign;
	char	*c;

	sign = (n < 0) ? -1 : 1;
	len = ft_len(n);
	c = (char *)malloc(sizeof(char) * len + 1);
	if (c == NULL)
		return (0);
	c[len] = '\0';
	len--;
	while (len >= 0)
	{
		c[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		c[0] = '-';
	return (c);
}
