/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:08:12 by codespace         #+#    #+#             */
/*   Updated: 2025/04/04 20:03:25 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_fill(char **map, int x, int y, t_floodfill *data)
{
	if (x < 0 || y < 0 || y >= data->size.width || x >= data->size.height
		|| map[x][y] == 'v' || map[x][y] == '1')
		return ;
	if (map[x][y] == 'E')
	{
		data->exit_reached = 1;
		return ;
	}
	map[x][y] = 'v';
	flood_fill(map, x + 1, y, data);
	flood_fill(map, x - 1, y, data);
	flood_fill(map, x, y + 1, data);
	flood_fill(map, x, y - 1, data);
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
	return (position);
}

int	validate_flood_fill(char **map, t_floodfill *data)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				return (print_error("not all collectables are accessible\n"));
			y++;
		}
		x++;
	}
	if (!data->exit_reached)
		return (print_error("exit is not accessible\n"));
	return (1);
}

int	validate_road(t_list *map)
{
	char		**arr;
	t_floodfill	data;
	t_player	start_position;

	data.exit_reached = 0;
	data.size.height = ft_lstsize(map);
	data.size.width = ft_strlen(map->content);
	arr = map_to_array(map, data.size);
	start_position = find_player(arr);
	flood_fill(arr, start_position.x, start_position.y, &data);
	if (!validate_flood_fill(arr, &data))
		return (free_arr(arr), 0);
	free_arr(arr);
	return (1);
}
