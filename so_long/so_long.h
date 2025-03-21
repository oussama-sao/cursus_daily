/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:40:16 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/21 20:28:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "gnl/get_next_line_bonus.h"

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
void	valid_name(char *filename);
void	read_map(char *filename, t_list **lst);
int		valid_map(t_list *map);
int		straight_lines(t_list *map);
int		validate_walls(t_list *map);
int		validate_element(t_list *map);
int		search_element(t_list *map, char element);
int		print_error(char *str);
int		line_len(char *line);

#endif