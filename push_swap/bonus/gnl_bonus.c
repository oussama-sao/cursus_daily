/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 02:58:47 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/12 19:41:32 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*gnl(int fd)
{
	char	*line;
	int		error;
	char	buffer[2];

	line = ft_strdup("");
	error = 1;
	while (error)
	{
		error = read(fd, buffer, 1);
		buffer[1] = '\0';
		line = ft_strjoin_and_free(line, buffer);
		if (buffer[0] == '\n')
			break ;
	}
	if (error <= 0)
	{
		free (line);
		return (NULL);
	}
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
