/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:40:35 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/21 21:27:00 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress_printf(void *ptr)
{
	int				count;
	int				tmp;
	unsigned long	adr;

	adr = (unsigned long)ptr;
	count = 0;
	if (ft_putstr_printf("0x") < 0)
		return (-1);
	count += 2;
	if (adr == 0)
	{
		if (ft_putchar_printf('0') < 0)
			return (-1);
		count++;
	}
	else
	{
		tmp = ft_puthexa_printf(adr, 0);
		if (tmp < 0)
			return (-1);
		count += tmp;
	}
	return (count);
}
