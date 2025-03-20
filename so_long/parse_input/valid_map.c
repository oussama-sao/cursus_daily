/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 03:37:44 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/20 01:38:11 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	straight_lines(t_list *map)
{
	int		line_len;

	line_len = ft_strlen(map->content);
	while (map)
	{
		if (ft_strlen(map->content) != line_len)
			return (print_error("lines are not straight\n"));
		map = map->next;
	}
	return (1);
}

int	validate_walls(t_list *map)
{
	int		i;
	char	*last;
	char	*first;
	char	*line;

	i = 0;
	first = map->content;
	last = ft_lstlast(map)->content;
	while (first[i])
	{
		if (first[i] != '1' || last[i] != '1')
			return (print_error("not arounded by walls\n"));
		i++;
	}
	while (map)
	{
		line = map->content;
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (print_error("not arounded by walls\n"));
		map = map->next;
	}
	return (1);
}

int	validate_element(t_list *map)
{
	int	count;

	count = 0;
	count = search_element(map, 'P');
		if (count != 1)
			return (print_error("player error !!\n"));
	count = search_element(map, 'E');
	if (count != 1)
		return (print_error("exit door error !!\n"));
	count = search_element(map, 'C');
	if (!count)
		return (print_error("collectable missing !!\n"));
	return (1);
}
