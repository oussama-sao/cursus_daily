/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:33:00 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/22 02:22:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_error(char *filename)
{
	t_list	*map;

	map = NULL;
	valid_name(filename);
	read_map(filename, &map);
	if (!valid_map(map))
	{
		ft_lstclear(&map, free);
		exit (1);
	}
	ft_lstclear(&map, free);
}
