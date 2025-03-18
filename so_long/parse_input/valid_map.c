/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 03:37:44 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/17 03:55:57 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_straight_lines(t_list *map)
{
	int		line_len;

	line_len = ft_strlen(map->content);
	while (map)
	{
		if (ft_strlen(map->content) != line_len)
			exit (1);
		map = map->next;
	}
}

void	is_arounded_by_walls(t_list *map)
{
	int		i;
	t_list	*last;
	t_list	*first;

	i = 0;
	first = map;
	last = ft_lstlast(map);
	
	while (map)
	{

	}
}