/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:23:45 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/20 19:09:16 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	checkerror(int *count, int tmp_count, va_list lst)
{
	if (tmp_count < 0)
	{
		va_end(lst);
		return (-1);
	}
	*count += tmp_count;
	return (0);
}

int	ft_witchformat(char current, va_list lst)
{
	int	count;

	count = 0;
	
	if (current == 'c')
		count += ft_putchar_printf(va_arg(lst, int));
	else if (current == 's')
		count += ft_putstr_printf(va_arg(lst, char *));
	else if (current == 'd' || current == 'i')
		count += ft_putnbr_printf(va_arg(lst, int));
	else if (current == 'u')
		count += ft_putnbr_u_printf(va_arg(lst, unsigned int));
	else if (current == 'p')
		count += ft_putaddress_printf(va_arg(lst, void *));
	else if (current == 'x')
		count += ft_puthexa_printf(va_arg(lst, unsigned int), 0);
	else if (current == 'X')
		count += ft_puthexa_printf(va_arg(lst, unsigned int), 1);
	else if (current == '%')
		count += ft_putpourcent_printf();
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	int		tmp;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		tmp = 0;
		if (str[i] == '%')
		{
			i++;
			tmp = ft_witchformat(str[i], args);
		}
		else
			tmp = ft_putchar_printf(str[i]);
		if (checkerror(&count, tmp, args) < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (count);
}

int main()
{
	char *a = "oussa";
	int i =printf("helloworold! \n%s ma", a);
	printf("\n%d\n",i);
}
