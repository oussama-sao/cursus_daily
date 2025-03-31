/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 03:41:10 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/31 06:44:30 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_player_view(t_game *game, int dx, int dy)
{
	mlx_destroy_image(game->mlx, game->player);
	if (dx == 0 && dy == -1)
		game->player = xpm_file(game, "assets/player.xpm");
	else if (dx == 0 && dy == 1)
		game->player = xpm_file(game, "assets/collectable.xpm");
	else if (dx == -1 && dy == 0)
		game->player = xpm_file(game, "assets/floorrocks.xpm");
	else if (dx == 1 && dy == 0)
		game->player = xpm_file(game, "assets/wall.xpm");
}

void	update_map(t_game *game, int new_x, int new_y)
{
	char *tile = &game->map[new_x][new_y];

	if (*tile == 'C')
	{
		game->coins_count--;
		*tile = '0';
	}
	else if (*tile == 'E' && game->coins_count == 0)
	{
		printf("You win!\n");
		exit_game(game);
	}
	update_exit_image(game);
	game->map[game->pos.x][game->pos.y] = '0';
	game->map[new_x][new_y] = 'P';
	game->pos.x = new_x;
	game->pos.y = new_y;
}

void	move_player(t_game *game, int dx, int dy)
{
	int new_x = game->pos.x + dx;
	int new_y = game->pos.y + dy;

	if (!can_move_to(game, new_x, new_y))
		return;
	printf("move %d\n", game->move_count++);
	update_map(game, new_x, new_y);
	// update_player_view(game, dx, dy);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		exit_game(game);
	else if (keycode == 119)
		move_player(game, -1, 0);
	else if (keycode == 115)
		move_player(game, 1, 0);
	else if (keycode == 97)
		move_player(game, 0, -1);
	else if (keycode == 100)
		move_player(game, 0, 1);
	return (0);
}
