/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmodulo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 11:13:21 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/22 09:43:53 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printmodulo(t_option option)
{
	int g_count;

	g_count = 0;
	if (option.flag_minus == 1)
		g_count += ft_putstr_len("%", 1);
	g_count += ft_put_zero_space(option.width, 1, option.flag_zero);
	if (option.flag_minus == 0)
		g_count += ft_putstr_len("%", 1);
	return (g_count);
}
