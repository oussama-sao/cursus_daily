/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 03:27:57 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/31 07:02:38 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_collectables(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	*xpm_file(t_game *game, char *path)
{
		return (mlx_xpm_file_to_image(game->mlx, path,
										   &game->img_width, &game->img_height));
}

void	update_exit_image(t_game *game)
{
	if (game->coins_count == 0)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = xpm_file(game, "assets/exitopen.xpm");
		if (!game->exit)
		{
			print_error("loading textures error\n");
			exit (1);
		}
	}
}

int	can_move_to(t_game *game, int x, int y)
{
	char tile = game->map[x][y];

	if (tile == '1')
		return (0);
	if (tile == 'E' && game->coins_count > 0)
		return (0);
	return (1);
}

int	clear_mlx(t_game *game)
{
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_arr(game->map);
	exit(0);
	return (0);
}
