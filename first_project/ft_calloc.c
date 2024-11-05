/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:38:37 by oessaoud          #+#    #+#             */
/*   Us2dated: 2024/11/05 11:08:24 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
// #include <stdlib.h>
// void	*ft_calloc(size_t count, size_t size)
// {
// 	size_t			total;
// 	size_t			i;
// 	unsigned char	*s2;

// 	i = 0;
// 	if (count && SIZE_MAX / count < size)
// 		return (NULL);
// 	total = count * size;
// 	s2 = malloc(total);
// 	if (!s2)
// 		return (NULL);
// 	ft_memset(s2, 0, total);
// 	return (s2);
// }

int main ()
{
	char *s2 = malloc(0);
	// char *s22 = ft_calloc(0, 0);
	 *s2 = 'b';
	printf("\n////\'%c\'\n%p",*s2,s2);
	// s2rintf("\n****%s\n%s2",s22,s22);
	return 0;
}
