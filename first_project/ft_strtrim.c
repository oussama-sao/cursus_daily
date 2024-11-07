/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:40:16 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/06 19:36:31 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_index(char const *s, char const *set, size_t *start)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	*start = 0;
	while (*start < len_s && ft_strchr(set, s[*start]))
	{
		(*start)++;
	}
	while (len_s > *(start) && ft_strchr(set, s[len_s - 1]))
	{
		len_s--;
	}
	return (len_s - (*start));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len_new;
	char	*newstr;

	if (!s1 || !set)
		return (NULL);
	len_new = ft_index(s1, set, &start);
	newstr = ft_substr(s1, start, len_new);
	return (newstr);
}
