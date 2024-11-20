/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:39:30 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/21 00:08:43 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_u_printf(unsigned int nbr)
{
	int	count;
	int	tmp;

	count = 0;
	if (nbr >= 10)
	{
		tmp = ft_putnbr_u_printf(nbr / 10);
		count += tmp;
	}
	tmp = ft_putchar_printf(nbr % 10 + '0');
	if (tmp < 0)
		return (-1);
	count += tmp;
	return (count);
}