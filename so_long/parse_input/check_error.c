/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:33:00 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/20 02:38:35 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_error(char *filename)
{
	t_list	*map;

	map = NULL;
	valid_name(filename);
	read_map(filename, &map);
	valid_map(map);
}
