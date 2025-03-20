/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:34:56 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/20 03:09:18 by oessaoud         ###   ########.fr       */
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

void	valid_map(t_list *map)
{
	if (!map || !map->next || !map->next->next)
		exit (1);
	if (!straight_lines(map))
		exit (1);
	if (validate_walls(map))
		printf("valid walls\n");
	if (validate_element(map))
		printf("valid elements\n");
	// is_road_ok(map);//is the door and coins are reachable; flood_fill; .../ ia there other elements / 
}
