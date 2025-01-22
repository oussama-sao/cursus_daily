/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:40:53 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/21 21:43:16 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_puthexa_printf(unsigned long nbr, short isupper, int *count)
{
	const char	*base = "0123456789abcdef";
	const char	*base_upper = "0123456789ABCDEF";

	if (isupper)
		base = base_upper;
	if (nbr >= 16)
		ft_puthexa_printf(nbr / 16, isupper, count);
	ft_putchar_printf(base[nbr % 16], count);
}
