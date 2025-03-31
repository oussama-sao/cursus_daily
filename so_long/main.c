/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:51:48 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/31 07:03:21 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc == 2)
	{
		check_error(argv[1]);
		game.mlx = mlx_init();
		game.filename = argv[1];
		load_map(&game);
		game.screen_width = 0;
		game.screen_height = 0;
		mlx_get_screen_size(game.mlx, &game.screen_width, &game.screen_height);
		if (game.map_height * 55 > game.screen_height ||
				game.map_width * 55 > game.screen_width)
		{
			ft_putstr_fd("Error: Map is too big for the screen!\n", 2);
			clear_mlx(&game);
		}
		load_element_from_xpm(&game);
		game.win = mlx_new_window(game.mlx, game.map_width * 55,
			game.map_height * 55, "so_long");
		mlx_hook(game.win, 17, 0, exit_game, &game);
		mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
		render_map(&game);
		mlx_loop(game.mlx);
		return (0);
	}
}
//(add playerup playerdown xpm)
//norminette
//bonus