/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamoutaf <pamoutaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:55:58 by pamoutaf          #+#    #+#             */
/*   Updated: 2021/10/19 13:43:15 by pamoutaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

char	*ft_itoa(long nbr);
size_t	ft_strlen(const char *str);
void	ft_putnbr(long n);
int		ft_nbrlen(int nbr);
void	ft_putstr(const char *s);
int		ft_len_hex(unsigned int nbr);
char	ft_conversion_id(va_list params);
size_t	ft_double_percent(const char c);
char	ft_conversion_s(va_list params);
int		ft_conversion_u(va_list params);
char	ft_conversion_c(va_list params);
int		ft_conversion_x_low(va_list params);
int		ft_conversion_x_up(va_list params);
int		ft_printf(const char *str, ...);
void	ft_putchar(const char c);
void	ft_putnbr_u(unsigned int n);
void	ft_putnbr_hex(unsigned int n);
int		ft_conversion_p(va_list params);
int		ft_nbrlen_u(unsigned int nbr);
void	ft_putnbr_p(unsigned long n);
int		ft_len_p(unsigned long nbr);
#endif