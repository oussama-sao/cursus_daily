/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:38:59 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/21 21:27:14 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_printf(int nbr)
{
	int	count;
	int	tmp;

	count = 0;
	if (nbr == -2147483648)
		return (ft_putstr_printf("-2147483648"));
	if (nbr < 0)
	{
		if (ft_putchar_printf('-') < 0)
			return (-1);
		nbr *= -1;
		count++;
	}
	if (nbr >= 10)
	{
		tmp = ft_putnbr_printf(nbr / 10);
		if (tmp < 0)
			return (-1);
		count += tmp;
	}
	tmp = ft_putchar_printf(nbr % 10 + '0');
	if (tmp < 0)
		return (-1);
	count += tmp;
	return (count);
}
