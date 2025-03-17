/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 22:48:03 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/04 14:30:59 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len_copy;

	len_copy = ft_strlen(s1) + 1;
	copy = malloc(len_copy);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, len_copy);
	return (copy);
}
