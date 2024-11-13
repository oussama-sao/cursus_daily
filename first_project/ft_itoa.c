/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:59:22 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/13 14:35:34 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	len_int(int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		count ++;
		i *= -1;
	}
	while (i > 0)
	{
		count++;
		i /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
	{
	int		i;
	char	*number_in_char;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = len_int(n);
	i = len;
	number_in_char = malloc(sizeof(char) * (len + 1));
	if (!number_in_char)
		return (NULL);
	if (n < 0)
	{
		number_in_char[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		number_in_char[--i] = (n % 10) + '0';
		n /= 10;
	}
	number_in_char[len] = '\0';
	return (number_in_char);
}
