/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:33:00 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/20 03:57:32 by oessaoud         ###   ########.fr       */
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
	//check road function
	ft_lstclear(&map, free);
}
