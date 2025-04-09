/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 12:18:46 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/20 09:52:20 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_put_part_str(char *str, t_option option)
{
	int g_count;

	g_count = 0;
	if (option.dot >= 0)
	{
		g_count += ft_put_zero_space(option.dot, ft_strlen_size_t(str), 0);
		g_count += ft_putstr_len(str, option.dot);
	}
	else
		g_count += ft_putstr_len(str, ft_strlen_size_t(str));
	return (g_count);
}

int			ft_printstring(char *str, t_option option)
{
	int g_count;

	g_count = 0;
	if (!str)
		str = "(null)";
	if (option.dot >= 0 && (size_t)option.dot > ft_strlen_size_t(str))
		option.dot = ft_strlen_size_t(str);
	if (option.flag_minus == 1)
		g_count += ft_put_part_str(str, option);
	if (option.dot >= 0)
		g_count += ft_put_zero_space(option.width, option.dot, 0);
	else
		g_count += ft_put_zero_space(option.width, ft_strlen_size_t(str), 0);
	if (option.flag_minus == 0)
		g_count += ft_put_part_str(str, option);
	return (g_count);
}
