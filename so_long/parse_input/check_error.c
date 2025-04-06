/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:33:00 by oessaoud          #+#    #+#             */
/*   Updated: 2025/04/05 18:54:35 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	is_folder(char *filename)
{
	int		fd;
	char	buffer;

	fd = open (filename, O_RDONLY);
	read (fd, &buffer, 0);
	if (errno == EISDIR)
	{
		print_error("is a directory\n");
		exit (1);
	}
}

void	check_error(int argc, char *filename)
{
	t_list	*map;

	if (argc != 2)
	{
		print_error("argument number must be 2\n");
		exit (1);
	}
	map = NULL;
	is_folder(filename);
	valid_name(filename);
	read_map(filename, &map);
	if (!valid_map(map))
	{
		ft_lstclear(&map, free);
		exit (1);
	}
	ft_lstclear(&map, free);
}
