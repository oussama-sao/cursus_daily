/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:29:15 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/03 23:38:21 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && i < n && s1[i] == s2[i])
		i++;
	if (s1[i] && s2[i] && i < n)
		return (s1[i] - s2[i]);
	return (0);
}
