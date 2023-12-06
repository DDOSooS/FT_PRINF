/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddos <ddos@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:05:50 by aghergho          #+#    #+#             */
/*   Updated: 2023/12/06 18:41:30 by ddos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	in_array(char c)
{
	char	*lst;
	int		i;

	i = -1;
	lst = "cspdiuxX%";
	while (lst[++i])
		if (lst[i] == c)
			return (1);
	return (0);
}

void ft_checker(char format, va_list arg)
{   
    if (format == '%')
        ft_putchar('%');
    else if (format == 'd' || format == 'i')
		ft_put_nbr(va_arg(arg, int));
    else if (format == 'c')
        ft_putchar(va_arg(arg, int));
    else if (format == 's')
        ft_putstr(va_arg(arg, char *));
    else if (format == 'u')
        ft_put_unsigned_nbr(va_arg(arg, unsigned int));
    else if (format == 'x')
        ft_put_hex_nbr(va_arg(arg, unsigned int), 0);
    else if (format == 'X')
        ft_put_hex_nbr(va_arg(arg, unsigned int), 1);
    else if (format == 'p')
        ft_put_adresse(va_arg(arg, void *));
}

int ft_printf(const char *format, ...)
{
	va_list arg;
	int		i;

	if (! format)
		return (0);
	i = 0;
	va_start(arg, format);
	while(format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i++]);
		else if (format[i + 1] && in_array(format[i + 1]))
		{	
			ft_checker(format[i + 1], arg);
			i += 2;
		}
		else
			return (0);
	}
	va_end(arg);
	return (1);	
}