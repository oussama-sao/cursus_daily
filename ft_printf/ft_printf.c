/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:23:45 by oessaoud          #+#    #+#             */
/*   Updated: 2024/12/02 16:58:12 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_witchformat(char current, va_list lst, int *count)
{
	if (current == 'c')
		ft_putchar_printf(va_arg(lst, int), count);
	else if (current == 's')
		ft_putstr_printf(va_arg(lst, char *), count);
	else if (current == 'd' || current == 'i')
		ft_putnbr_printf(va_arg(lst, int), count);
	else if (current == 'u')
		ft_putnbr_u_printf((unsigned int)va_arg(lst, unsigned int), count);
	else if (current == 'p')
		ft_putaddress_printf(va_arg(lst, void *), count);
	else if (current == 'x' || current == 'X')
		ft_puthexa_printf(va_arg(lst, unsigned int), current == 'X', count);
	else if (current == '%')
		ft_putpourcent_printf(count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_witchformat(str[i], args, &count);
		}
		else
			ft_putchar_printf(str[i], &count);
		i++;
	}
	va_end(args);
	return (count);
}
