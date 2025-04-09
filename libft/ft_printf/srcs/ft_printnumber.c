/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 13:46:33 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/20 09:48:17 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_in_put_part_int(char *d_i, int save_i, t_option option)
{
	int g_count;

	g_count = 0;
	if (save_i < 0 && option.dot >= 0)
		ft_putchar_int('-');
	if (option.dot >= 0)
		g_count += ft_put_zero_space(option.dot - 1, ft_strlen_size_t(d_i) - 1, 1);
	g_count += ft_putstr_len(d_i, ft_strlen_size_t(d_i));
	return (g_count);
}

int			ft_put_part_int(char *d_i, int save_i, t_option option)
{
	int g_count;

	g_count = 0;
	if (option.flag_minus == 1)
		g_count += ft_in_put_part_int(d_i, save_i, option);
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
		g_count += ft_in_put_part_int(d_i, save_i, option);
	return (g_count);
}

int			ft_printnumber(int i, t_option option)
{
	char		*d_i;
	int			save_i;
	int			g_count;

	save_i = i;
	g_count = 0;
	if (option.dot == 0 && i == 0)
	{
		g_count += ft_put_zero_space(option.width, 0, 0);
		return (g_count);
	}
	if (i < 0 && (option.dot >= 0 || option.flag_zero == 1))
	{
		if (option.flag_zero == 1 && option.dot < 0)
			ft_putstr_len("-", 1);
		i *= -1;
		option.flag_zero = 1;
		option.width--;
		g_count++;
	}
	d_i = ft_itoa_flag(i, option);
	g_count += ft_put_part_int(d_i, save_i, option);
	free(d_i);
	return (g_count);
}
