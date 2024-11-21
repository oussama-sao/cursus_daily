/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:37:41 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/21 20:57:39 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putstr_printf(char *str)
{
	int	i;
	int	count;
	int	tmp;

	count = 0;
	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		tmp = ft_putchar_printf(str[i]);
		if (tmp < 0)
			return (-1);
		count += tmp;
		i++;
	}
	return (count);
}
