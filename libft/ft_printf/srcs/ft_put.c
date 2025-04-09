/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:35:33 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/20 10:03:23 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_putstr_len(char *str, int len)
{
	int char_count;

	char_count = 0;
	while (str[char_count] && char_count < len)
		ft_putchar_int(str[char_count++]);
	return (char_count);
}

int			ft_put_zero_space(int width, int minus, int has_zero)
{
	int g_count;

	g_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar_int('0');
		else
			ft_putchar_int(' ');
		width--;
		g_count++;
	}
	return (g_count);
}
