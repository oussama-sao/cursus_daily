/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:38:37 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/11 11:01:11 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	unsigned char	*s2;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	total = count * size;
	s2 = malloc(total);
	if (!s2)
		return (NULL);
	ft_memset(s2, 0, total);
	return (s2);
}
