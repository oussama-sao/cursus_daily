/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:40:16 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/20 01:27:59 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "gnl/get_next_line_bonus.h"

void	check_error(char *filename);
void	valid_name(char *filename);
void	read_map(char *filename, t_list **lst);
void	valid_map(t_list *map);
int		straight_lines(t_list *map);
int		validate_walls(t_list *map);
int		validate_element(t_list *map);
int		search_element(t_list *map, char element);
int		print_error(char *str);


#endif