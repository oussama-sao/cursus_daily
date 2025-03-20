/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:40:16 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/19 23:56:01 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"

int	valid_name(char *filename);
int	check_error(char *filename);
int	valid_map(t_list *map);
int	is_straight_lines(t_list *map);
int	validate_walls(t_list *map);
int	search_element(t_list *map, char element);

#endif