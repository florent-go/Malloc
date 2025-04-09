/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:03:15 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/22 09:53:46 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_in_put_part_hexa(char *hexa, t_option option)
{
	int g_count;

	g_count = 0;
	if (option.dot >= 0)
		g_count += ft_put_zero_space(option.dot - 1, ft_strlen_size_t(hexa) - 1, 1);
	g_count += ft_putstr_len(hexa, ft_strlen_size_t(hexa));
	return (g_count);
}

int		ft_put_part_hexa(char *hexa, t_option option)
{
	int g_count;

	g_count = 0;
	if (option.flag_minus == 1)
		g_count += ft_in_put_part_hexa(hexa, option);
	if (option.dot >= 0 && (size_t)option.dot < ft_strlen_size_t(hexa))
		option.dot = ft_strlen_size_t(hexa);
	if (option.dot >= 0)
	{
		option.width -= option.dot;
		g_count += ft_put_zero_space(option.width, 0, 0);
	}
	else
		g_count += ft_put_zero_space(option.width,
		ft_strlen_size_t(hexa), option.flag_zero);
	if (option.flag_minus == 0)
		g_count += ft_in_put_part_hexa(hexa, option);
	return (g_count);
}

int		ft_printhexa(unsigned int nbr, int min, t_option option)
{
	char	*hexa;
	int		g_count;

	g_count = 0;
	if (option.dot == 0 && nbr == 0)
	{
		g_count += ft_put_zero_space(option.width, 0, 0);
		return (g_count);
	}
	hexa = ft_hexatoi((unsigned long long)nbr, 16);
	if (min == 1)
		hexa = ft_str_tolower(hexa);
	g_count += ft_put_part_hexa(hexa, option);
	free(hexa);
	return (g_count);
}
