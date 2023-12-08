/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddos <ddos@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:05:50 by aghergho          #+#    #+#             */
/*   Updated: 2023/12/06 21:51:30 by aghergho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

int	in_array(char c, char *tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		if (tab[i] == c)
			return (1);
	return (0);
}

void	ft_checker(char format, va_list arg, int *counter)
{
	if (format == '%')
		ft_putchar('%', counter);
	else if (format == 'd' || format == 'i')
		ft_put_nbr(va_arg(arg, int), counter);
	else if (format == 'c')
		ft_putchar(va_arg(arg, int), counter);
	else if (format == 's')
		ft_putstr(va_arg(arg, char *), counter);
	else if (format == 'u')
		ft_put_unsigned_nbr(va_arg(arg, unsigned int), counter);
	else if (format == 'x')
		ft_put_hex_nbr(va_arg(arg, unsigned int), 0, counter);
	else if (format == 'X')
		ft_put_hex_nbr(va_arg(arg, unsigned int), 1, counter);
	else if (format == 'p')
		ft_put_adresse(va_arg(arg, unsigned long), counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		wc_len;

	i = 0;
	wc_len = 0;
	va_start(arg, format);
	while (format && format[i])
	{
		if (format[i] == '%' && format[i + 1] && (in_array(format[i + 1, "cspdiuxX%"])))
		{
			ft_checker(format[i + 1], arg, &wc_len);
			i += 2;
		}
		else
			ft_putchar(format[i++], &wc_len);
	}
	va_end(arg);
	return (wc_len);
}