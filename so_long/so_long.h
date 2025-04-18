/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:40:16 by oessaoud          #+#    #+#             */
/*   Updated: 2025/04/05 18:28:42 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"
# include "fcntl.h"
# include "errno.h"
# include <mlx.h>

typedef struct t_map
{
	int	height;
	int	width;
}	t_map;

typedef struct t_floodfill
{
	t_map	size;
	int		exit_reached;
}	t_floodfill;

typedef struct t_player
{
	int	x;
	int	y;	
}	t_player;

void		check_error(int argc, char *filename);
void		flood_fill(char **map, int x, int y, t_floodfill *data);
char		**map_to_array(t_list *map, t_map size);
t_player	find_player(char **map);
int			validate_flood_fill(char **map, t_floodfill *data);
int			validate_road(t_list *map);
void		valid_name(char *filename);
int			valid_map(t_list *map);
int			search_element(t_list *map, char element);
int			print_error(char *str);
void		read_map(char *filename, t_list **lst);
int			line_len(char *line);
void		free_arr(char **arr);
int			straight_lines(t_list *map);
int			validate_walls(t_list *map);
int			validate_element(t_list *map);
int			has_stranger_element(t_list *map);

typedef struct t_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	void		*wall;
	void		*floor;
	void		*player;
	void		*collectable;
	void		*exit;
	int			img_width;
	int			img_height;
	char		*filename;
	t_player	pos;
	int			coins_count;
	int			move_count;
	int			screen_height;
	int			screen_width;
}	t_game;

void		load_element_from_xpm(t_game *game);
void		load_map(t_game *game);
void		render_map(t_game *game);
int			exit_game(t_game *game);
int			count_collectables(char **map);
int			handle_keypress(int keycode, t_game *game);
void		move_player(t_game *game, int dx, int dy);
void		*xpm_file(t_game *game, char *path);
void		update_exit_image(t_game *game);
int			can_move_to(t_game *game, int x, int y);
void		update_map(t_game *game, int new_x, int new_y);
void		update_player_view(t_game *game, int dx, int dy);
int			clear_mlx(t_game *game);
void		put_image(t_game *game, void *texture, int x, int y);

#endif