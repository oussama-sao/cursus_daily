/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:08:12 by codespace         #+#    #+#             */
/*   Updated: 2025/03/22 02:56:41 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int x, int y, t_map size)
{
	if (x < 0 || y < 0 || y >= size.width || x >= size.height ||
			map[x][y] == 'v' || map[x][y] == '1')
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
	arr[i] = NULL;
	return (arr);
}

t_player	find_player(char **map)
{
	int			x;
	int			y;
	t_player	position;

	x = 0;
	position.x = -1;
	position.y = -1;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
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

int	validate_road(t_list *map)
{
	char		**arr;
	t_map		size;
	t_player	start_position;
	size.height = ft_lstsize(map);
	size.width = ft_strlen(map->content);
	arr = map_to_array(map, size);
	start_position = find_player(arr);
	flood_fill(arr, start_position.x, start_position.y, size);
	if (!validate_flood_fill(arr, size))
		return (free_arr(arr), 0);
	free_arr(arr);
	return (1);		
}
