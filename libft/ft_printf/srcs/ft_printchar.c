/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:12:23 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/20 09:52:47 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printchar(char c, t_option option)
{
	int g_count;

	g_count = 0;
	if (option.flag_minus == 1)
		ft_putchar_int(c);
	g_count = ft_put_zero_space(option.width, 1, 0);
	if (option.flag_minus == 0)
		ft_putchar_int(c);
	return (g_count + 1);
}
