/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:34:56 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/20 03:57:46 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	valid_name(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	i -= 4;
	if (ft_strncmp(filename + i, ".ber", 4))
		exit (1);
}

int	valid_map(t_list *map)
{
	if (!map || !map->next || !map->next->next)
		return (0);
	if (!straight_lines(map))
		return (0);
	if (!validate_walls(map))
		return (0);
	if (!validate_element(map))
		return (0);
	//is_road_ok(map);//is the door and coins are reachable; flood_fill; .../ ia there other elements / 
	return (1);
}
