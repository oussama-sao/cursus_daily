/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:39:30 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/21 22:16:00 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u_printf(unsigned int nbr, int *count)
{
	if (nbr >= 10)
		ft_putnbr_u_printf(nbr / 10, count);
	ft_putchar_printf((nbr % 10 + '0'), count);
}
