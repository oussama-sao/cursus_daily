/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:57:48 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/12 22:22:09 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lend;
	size_t	lens;
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	if (lend >= dstsize)
		return (dstsize + lens);
	if (dstsize > 0)
	{
		while (lend + i < dstsize - 1 && src[i])
		{
			dst[lend + i] = src[i];
			i++;
		}
		dst[lend + i] = '\0';
	}
	return (lend + lens);
}
