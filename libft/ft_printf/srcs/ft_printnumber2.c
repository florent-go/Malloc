/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:43:26 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/20 09:50:36 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_in_put_part_unsigned_int(char *d_i, t_option option)
{
	int g_count;

	g_count = 0;
	if (option.dot >= 0)
		g_count += ft_put_zero_space(option.dot - 1, ft_strlen_size_t(d_i) - 1, 1);
	g_count += ft_putstr_len(d_i, ft_strlen_size_t(d_i));
	return (g_count);
}

int			ft_put_part_unsigned_int(char *d_i, t_option option)
{
	int g_count;

	g_count = 0;
	if (option.flag_minus == 1)
		g_count += ft_in_put_part_unsigned_int(d_i, option);
	if (option.dot >= 0 && (size_t)option.dot < ft_strlen_size_t(d_i))
		option.dot = ft_strlen_size_t(d_i);
	if (option.dot >= 0)
	{
		option.width -= option.dot;
		g_count += ft_put_zero_space(option.width, 0, 0);
	}
	else
		g_count += ft_put_zero_space(option.width,
								ft_strlen_size_t(d_i), option.flag_zero);
	if (option.flag_minus == 0)
		g_count += ft_in_put_part_unsigned_int(d_i, option);
	return (g_count);
}

int			ft_printnumber2(unsigned int i, t_option option)
{
	char	*unsigned_int;
	int		g_count;

	g_count = 0;
	i = (unsigned int)(4294967295 + 1 + i);
	if (option.dot == 0 && i == 0)
	{
		g_count += ft_put_zero_space(option.width, 0, 0);
		return (g_count);
	}
	unsigned_int = ft_unsigned_itoa(i);
	g_count += ft_put_part_unsigned_int(unsigned_int, option);
	free(unsigned_int);
	return (g_count);
}
