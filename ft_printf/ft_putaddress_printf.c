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

void	ft_putaddress_printf(void *ptr, int *count)
{
	unsigned long	adr;

	adr = (unsigned long)ptr;
	if (adr == 0)
	{
		ft_putstr_printf("(nil)", count);
		return ;
	}
	ft_putstr_printf("0x", count);
	ft_puthexa_printf((unsigned long)adr, 0, count);
}
