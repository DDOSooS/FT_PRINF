/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddos <ddos@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:18:24 by ddos              #+#    #+#             */
/*   Updated: 2023/12/06 11:48:06 by ddos             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{
	(*counter)++;
	write (1, &c, 1);
}

void	ft_putstr(const char *str, int *counter)
{
	int		i;

	if (!str)
		return (ft_putstr("(null)", counter));
	i = 0;
	while (str[i])
		ft_putchar(str[i++], counter);
}
