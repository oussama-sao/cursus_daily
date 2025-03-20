/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:52:04 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/20 03:16:00 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	search_element(t_list *map, char element)
{
	int		count;
	int		i;
	char	*line;

	count = 0;
	while (map)
	{
		i = 0;
		line = map->content;
		while (line[i])
		{
			if (line[i] == element)
				count++;
			i++;
		}
		map = map->next;
	}
	return (count);
}

int	print_error(char *str)
{
	ft_putstr_fd("Error\n",  2);
	ft_putstr_fd(str, 2);
	return (0);
}

void	read_map(char *filename, t_list **lst)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(lst, ft_lstnew(line));
	}
	close(fd);
}

int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}
