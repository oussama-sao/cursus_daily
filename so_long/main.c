/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:51:48 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/28 20:44:49 by oessaoud         ###   ########.fr       */
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
		load_element_from_xpm(&game);
		game.win = mlx_new_window(game.mlx, game.map_width * 55, game.map_height * 55, "so_long");
		
		render_map(&game);
		mlx_hook(game.win, 17, 0, exit_game, &game);
		mlx_loop(game.mlx);
		free_arr(game.map);
		return (0);
	}
}
