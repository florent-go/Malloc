/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 10:22:01 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/20 09:46:20 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_option	*ft_init_struct(t_option *option)
{
	option->flag_minus = 0;
	option->flag_zero = 0;
	option->width = 0;
	option->dot = -1;
	option->precision = 0;
	option->type = 0;
	return (option);
}

int			ft_flag_dico(va_list ap, const char *str,
												int g_count, t_option *option)
{
	while (str[g_count] != '\0')
	{
		if (str[g_count] == '0' && option->width == 0 &&
			option->flag_minus == 0)
			option->flag_zero = 1;
		if (str[g_count] == '-')
			*option = ft_flag_minus(option);
		if (str[g_count] == '.')
			g_count = ft_flag_dot(str, g_count, option, ap);
		if (str[g_count] == '*')
			*option = ft_flag_width(ap, option);
		if (ft_isdigit(str[g_count]))
			*option = ft_flag_digit(str[g_count], option);
		if (ft_type_of_format(str[g_count]))
		{
			option->type = str[g_count];
			break ;
		}
		g_count++;
	}
	return (g_count);
}

int			ft_dico(int c, va_list ap, t_option option)
{
	int g_count;

	g_count = 0;
	if (c == 's')
		g_count = ft_printstring(va_arg(ap, char *), option);
	if (c == 'c')
		g_count = ft_printchar(va_arg(ap, int), option);
	if (c == 'd' || c == 'i')
		g_count = ft_printnumber(va_arg(ap, int), option);
	if (c == 'u')
		g_count += ft_printnumber2(va_arg(ap, unsigned int), option);
	if (c == 'X')
		g_count += ft_printhexa(va_arg(ap, unsigned int), 0, option);
	if (c == 'x')
		g_count += ft_printhexa(va_arg(ap, unsigned int), 1, option);
	if (c == '%')
		g_count += ft_printmodulo(option);
	if (c == 'p')
		g_count = ft_printpointer(va_arg(ap, unsigned long long), option);
	return (g_count);
}

int			ft_g_error(va_list ap, const char *b_save, t_option *option)
{
	int				i;
	int				g_count;

	i = 0;
	g_count = 0;
	while (b_save[i] != '\0')
	{
		option = ft_init_struct(option);
		if (b_save[i] == '%' && b_save[i + 1])
		{
			i = ft_flag_dico(ap, b_save, ++i, option);
			if (ft_type_of_format(b_save[i]))
				g_count += ft_dico((char)option->type, ap, *option);
			else if (b_save[i])
				g_count += ft_putchar_int(b_save[i]);
		}
		else if (b_save[i] != '%')
			g_count += ft_putchar_int(b_save[i]);
		i++;
	}
	return (g_count);
}

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	int			g_count;
	t_option	*option;
	char		*b_save;

	g_count = 0;
	b_save = ft_strdup((char *)str);
	if (!(option = malloc(sizeof(t_option))))
		return (-1);
	va_start(ap, str);
	g_count = ft_g_error(ap, b_save, option);
	va_end(ap);
	free(b_save);
	free(option);
	return (g_count);
}
