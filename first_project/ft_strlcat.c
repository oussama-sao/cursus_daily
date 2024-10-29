/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:57:48 by oessaoud          #+#    #+#             */
/*   Updated: 2024/10/28 21:12:42 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lend;
	size_t	lens;
	int		i;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	if (lend == dstsize)
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
