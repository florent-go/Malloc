/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 10:08:54 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/18 11:45:08 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_option		ft_flag_minus(t_option *option)
{
	option->flag_minus = 1;
	option->flag_zero = 0;
	return (*option);
}

t_option		ft_flag_digit(char c, t_option *option)
{
	if (option->precision == 1)
		option->width = 0;
	option->width = (option->width * 10) + (c - '0');
	return (*option);
}

t_option		ft_flag_width(va_list ap, t_option *option)
{
	option->precision = 1;
	option->width = va_arg(ap, int);
	if (option->width < 0)
	{
		option->flag_minus = 1;
		option->flag_zero = 0;
		option->width *= -1;
	}
	return (*option);
}

int				ft_flag_dot(const char *save, int start,
				t_option *option, va_list ap)
{
	int i;

	i = start;
	i++;
	if (save[i] == '*')
	{
		option->dot = va_arg(ap, int);
		i++;
	}
	else
	{
		option->dot = 0;
		while (ft_isdigit(save[i]))
			option->dot = (option->dot * 10) + (save[i++] - '0');
	}
	return (i);
}
