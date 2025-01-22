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

#include "ft_printf_bonus.h"

void	ft_putnbr_printf(int nbr, int *count)
{
	if (nbr == -2147483648)
		return (ft_putstr_printf("-2147483648", count));
	if (nbr < 0)
	{
		ft_putchar_printf('-', count);
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbr_printf(nbr / 10, count);
	ft_putchar_printf(nbr % 10 + '0', count);
}
