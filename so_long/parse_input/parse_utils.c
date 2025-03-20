/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:52:04 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/19 23:55:49 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	search_element(t_list *map, char element)
{
	int		count;
	int		i;
	char	*line;

	count = 0;
	while (map)
	{
		i = 0;
		line = map->content;
		while (line[i])
		{
			if (line[i] == element)
				count++;
			i++;
		}
		map = map->next;
	}
	return (count);
}