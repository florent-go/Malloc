/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:33:32 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/22 09:43:20 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_in_put_part_pointer(char *pointer, t_option option)
{
	int g_count;

	g_count = 0;
	g_count += ft_putstr_len("0x", 2);
	if (option.dot >= 0)
	{
		g_count += ft_put_zero_space(option.dot, ft_strlen_size_t(pointer), 1);
		g_count += ft_putstr_len(pointer, option.dot);
	}
	else
		g_count += ft_putstr_len(pointer, ft_strlen_size_t(pointer));
	return (g_count);
}

int			ft_printpointer(unsigned long long nbr, t_option option)
{
	char	*pointer;
	int		g_count;

	g_count = 0;
	if (nbr == 0 && option.dot == 0)
	{
		g_count += ft_putstr_len("0x", 2);
		return (g_count += ft_put_zero_space(option.width, 0, 1));
	}
	pointer = ft_hexatoi(nbr, 16);
	pointer = ft_str_tolower(pointer);
	if ((size_t)option.dot < ft_strlen_size_t(pointer))
		option.dot = ft_strlen_size_t(pointer);
	if (option.flag_minus == 1)
		g_count += ft_in_put_part_pointer(pointer, option);
	g_count += ft_put_zero_space(option.width, ft_strlen_size_t(pointer) + 2, 0);
	if (option.flag_minus == 0)
		g_count += ft_in_put_part_pointer(pointer, option);
	free(pointer);
	return (g_count);
}
