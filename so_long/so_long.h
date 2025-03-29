/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:40:16 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/28 06:15:24 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "gnl/get_next_line_bonus.h"
#include "minilibx-linux/mlx.h"

typedef struct t_map
{
	int	height;
	int	width;
}	t_map;

typedef struct t_player
{
	int	x;
	int	y;	
}	t_player;

void	check_error(char *filename);
void	flood_fill(char **map, int x, int y, t_map size);
char	**map_to_array(t_list *map, t_map size);
t_player	find_player(char **map);
int	validate_flood_fill(char **map, t_map size);
int	validate_road(t_list *map);
void	valid_name(char *filename);
int	valid_map(t_list *map);
int	search_element(t_list *map, char element);
int	print_error(char *str);
void	read_map(char *filename, t_list **lst);
int	line_len(char *line);
void	free_arr(char **arr);
int	straight_lines(t_list *map);
int	validate_walls(t_list *map);
int	validate_element(t_list *map);
int	has_stranger_element(t_list *map);

typedef struct t_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectable;
	void	*exit;
	int		img_width;
	int		img_height;
	char	*filename;
}	t_game;

void	load_element_from_xpm(t_game *game);
void 	load_map(t_game *game);
void	render_map(t_game *game);
int		exit_game(t_game *game);

#endif