/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:40:53 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/21 00:51:10 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthexa_printf(unsigned int nbr, short isupper)
{
	const char	*base = "0123456789abcdef";
	const char	*base_upper = "0123456789ABCDEF";
	int			count;
	int			tmp;

	count = 0;
	if (isupper)
		base = base_upper;
	if (nbr >= 16)
	{
		tmp = ft_puthexa_printf(nbr / 16, isupper);
		if (tmp < 0)
			return (-1);
		count += tmp;
	}
	tmp = ft_putchar_printf(base[nbr % 16]);
	if (tmp < 0)
		return (-1);
	count += tmp;
	return (count);
}
