/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:08:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/21 21:23:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int x, int y, t_map size)
{
	if (x < 0 || y < 0 || y >= size.width || x >= size.height || map[x][y] == 'v')
		return ;
	map[x][y] = 'v';
	flood_fill(map, x + 1, y, size);
	flood_fill(map, x - 1, y, size);
	flood_fill(map, x, y + 1, size);
	flood_fill(map, x, y - 1, size);
}

char	**map_to_array(t_list *map, t_map size)
{
	int		i;
	char	**arr;

	arr = malloc((size.height + 1) * sizeof(char *));
	i = 0;
	while (map)
	{
		arr[i] = ft_strdup(map->content);
		map = map->next;
		i++;
	}
	arr[i] == NULL;
	return (arr);
}

t_player	find_player(char **map)
{
	int			x;
	int			y;
	t_player	position;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P');
			{
				position.x = x;
				position.y = y;
				return (position);
			}
			y++;
		}
		x++;
	}
}

int	validate_flood_fill(char **map, t_map size)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'E' || map[x][y] == 'C')
				return (print_error("road is not accessible\n"));
			y++;
		}
		x++;
	}
	return (1);
}

