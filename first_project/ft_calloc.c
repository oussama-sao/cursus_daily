/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:38:37 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/06 18:11:41 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	size_t			i;
	unsigned char	*s2;

	i = 0;
	if (count && SIZE_MAX / count < size)
		return (NULL);
	total = count * size;
	s2 = malloc(total);
	if (!s2)
		return (NULL);
	ft_memset(s2, 0, total);
	return (s2);
}
