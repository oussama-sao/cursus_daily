/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 02:22:33 by oessaoud          #+#    #+#             */
/*   Updated: 2025/04/04 19:59:25 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_image(t_game *game, void *texture, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win,
		texture, x * 55, y * 55);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == '1')
				put_image(game, game->wall, x, y);
			if (game->map[y][x] == '0')
				put_image(game, game->floor, x, y);
			else if (game->map[y][x] == 'E')
				put_image(game, game->exit, x, y);
			else if (game->map[y][x] == 'C')
				put_image(game, game->collectable, x, y);
			else if (game->map[y][x] == 'P')
				put_image(game, game->player, x, y);
			x++;
		}
		y++;
	}
}

void	load_map(t_game *game)
{
	t_map	size;
	t_list	*map1;

	map1 = NULL;
	read_map(game->filename, &map1);
	size.height = ft_lstsize(map1);
	size.width = ft_strlen(map1->content);
	game->map = map_to_array(map1, size);
	game->map_width = size.width - 1;
	game->map_height = size.height;
	ft_lstclear(&map1, free);
	game->coins_count = count_collectables(game->map);
	game->pos = find_player(game->map);
	game->move_count = 1;
	game->screen_width = 0;
	game->screen_height = 0;
}
