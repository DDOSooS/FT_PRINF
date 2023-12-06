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

void	ft_put_nbr(int  number)
{
	long	nb;

	nb = number;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_put_nbr(nb / 10);
		ft_put_nbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_put_unsigned_nbr(unsigned int number)
{
	char	degit;

	if (number > 9)
	{
		ft_put_nbr(number / 10);
		ft_put_nbr(number % 10);
	}
	degit = number + '0';
	ft_putchar(degit);
}

void	ft_put_adresse(void *ptr)
{
	int	*tmp;
	
	if (!ptr)
		return (ft_putstr("(nil)"));
	tmp = (int *)ptr;
	ft_putstr("0x");
	ft_put_hex_nbr(*tmp, 0);
}

void    ft_put_hex_nbr(unsigned int number, int	flag)
{
    char	*tab;

	if (flag)
		tab = "0123456879ABCDEF";
	else
		tab = "0123456789abcdef";
	if (number > 15)
	{
		ft_put_hex_nbr(number / 16, flag);
		ft_put_hex_nbr(number % 16, flag);
	}
	else
		ft_putchar(tab[number]);
}