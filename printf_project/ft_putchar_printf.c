/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:36:52 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/20 18:40:49 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putchar_printf(char c)
{
	int	checkerror;

	checkerror = write (1, &c, 1);
	if (checkerror < 0)
		return (-1);
	return (1);
}