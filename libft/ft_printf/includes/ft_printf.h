/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:30:38 by fgomez            #+#    #+#             */
/*   Updated: 2021/02/22 09:21:18 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../../includes/libft.h"

typedef struct	s_option
{
	int			flag_minus;
	int			flag_zero;
	int			width;
	int			dot;
	int			precision;
	int			type;
}				t_option;

int				ft_printf(const char *str, ...);
int				ft_printpointer(unsigned long long ull, t_option option);
int				ft_printhexa(unsigned int nbr, int maj, t_option option);
char			*ft_hexatoi(unsigned long long nbr, int base);
int				ft_printchar(char c, t_option option);
int				ft_putnbr_base(unsigned int nbr, char const *base);
int				ft_printmodulo(t_option option);
int				ft_dico(int c, va_list ap, t_option option);
int				ft_printstring(char *str, t_option option);
int				ft_printnumber2(unsigned int i, t_option option);
char			*ft_unsigned_itoa(int n);
int				ft_len(long int nbr);
int				ft_len2(unsigned long long nbr, int base);
char			*ft_itoa_flag(int n, t_option option);
int				ft_printnumber(int i, t_option option);
int				ft_isdigit(int c);
int				ft_type_of_format(int c);
char			*ft_strdup(char *src);
int				ft_putstr_len(char *str, int len);
int				ft_flags(va_list ap, const char *str,
				int g_count, t_option *option);
t_option		ft_flag_minus(t_option *option);
t_option		ft_flag_digit(char c, t_option *option);
t_option		ft_flag_width(va_list ap, t_option *option);
int				ft_put_zero_space(int width, int minus, int zero);
int				ft_flag_dot(const char *save, int start,
				t_option *option, va_list ap);

#endif
