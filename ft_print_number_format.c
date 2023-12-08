/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_format.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddos <ddos@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:25:08 by ddos              #+#    #+#             */
/*   Updated: 2023/12/06 16:03:25 by ddos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_nbr(int number, int *counter)
{
	long	nb;

	nb = number;
	if (nb < 0)
	{
		ft_putchar('-', counter);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_put_nbr(nb / 10, counter);
		ft_put_nbr(nb % 10, counter);
	}
	else
		ft_putchar(nb + '0', counter);
}

void	ft_put_unsigned_nbr(unsigned int number, int *counter)
{
	if (number > 9)
	{
		ft_put_unsigned_nbr(number / 10, counter);
		ft_put_unsigned_nbr(number % 10, counter);
	}
	else
		ft_putchar(number + '0', counter);
}

void	ft_put_hex_nbr(unsigned int number, int flag, int *counter)
{
	char	*tab;

	if (flag)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	if (number > 15)
	{
		ft_put_hex_nbr(number / 16, flag, counter);
		ft_put_hex_nbr(number % 16, flag, counter);
	}
	else
		ft_putchar(tab[number], counter);
}

void	ft_put_hex_nbr_long(unsigned long number, int flag, int *counter)
{
	char	*tab;

	if (flag)
		tab = "0123456879ABCDEF";
	else
		tab = "0123456789abcdef";
	if (number > 15)
	{
		ft_put_hex_nbr_long(number / 16, flag, counter);
		ft_put_hex_nbr_long(number % 16, flag, counter);
	}
	else
		ft_putchar(tab[number], counter);
}

void	ft_put_adresse(unsigned long ptr, int *counter)
{
	ft_putstr("0x", counter);
	ft_put_hex_nbr_long((unsigned long) ptr, 0, counter);
}
