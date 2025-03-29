/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 01:44:02 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/29 02:09:21 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_element_from_xpm(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx, "assets/wallxpm.xpm", &game->img_width, &game->img_height);
	game->floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &game->img_width, &game->img_height);
	game->player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &game->img_width, &game->img_height);
	game->collectable = mlx_xpm_file_to_image(game->mlx, "assets/collectable.xpm", &game->img_width, &game->img_height);
	game->exit = mlx_xpm_file_to_image(game->mlx, "assets/exitopen.xpm", &game->img_width, &game->img_height);
	if (!game->player || !game->collectable || !game->floor  || !game->exit || !game->wall)// || !game->wall || !game->floor || !game->exit || !game->collectable 
	{
		print_error("loading textures error\n");
		exit (1);
	}
}

int	exit_game(t_game *game)
{
	if (game->player)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->floor)
		mlx_destroy_image(game->mlx, game->floor);
	if (game->collectable)
		mlx_destroy_image(game->mlx, game->collectable);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);

	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}

	free_arr(game->map);
	exit(0);
	return (0);
}
