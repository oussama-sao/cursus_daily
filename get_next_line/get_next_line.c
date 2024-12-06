/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:45:34 by oessaoud          #+#    #+#             */
/*   Updated: 2024/12/06 18:29:27 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_text(int fd, char *text)
{
	int		i;
	char	*buffer;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		tmp = ft_strjoin(text, buffer);
		free (text);
		text = tmp;
	}
	free (buffer);
	return (text);
}

char	*get_line(char *text, int size)
{
	char	*line;
	int		i;

	if (!text)
		return (NULL);
	line = malloc(size + 1);
	if (!line)
		return (NULL);
	while (i < size)
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *text, int size)
{
	if (!text[size])
		return (NULL);
	return (ft_strdup(text + size));
}

char	*next_line(char **text)
{
	int		i;
	char	*line;
	char	*rest;

	if (!text || !*text || !**text)
		return (NULL);
	i = 0;
	while ((*text)[i] && (*text)[i] != '\n')
		i++;
	line = malloc(i + 1 + ((*text)[i] == '\n'));
	if (!line)
		return (NULL);
	line = get_line(*text, i + ((*text)[i] == '\n'));
	if (!line)
		return (NULL);
	rest = get_rest(*text, i + ((*text)[i] == '\n'));
	free(*text);
	*text = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = get_text(fd, text);
	line = next_line(&text);
	return (line);
}

// int main()
// {
// 	int i = open("example4.txt",O_RDONLY) ;
// 	char *s = NULL;
// 	s = get_next_line(i);
// 	 printf("%s",s);
// 	char *k = get_next_line(i);
//  	printf("%s",k);
// 	char *d = get_next_line(i);
//  	printf("%s",d);
// 	char *c = get_next_line(i);
//  	printf("%s",c);
// 	char *v = get_next_line(i);
//  	printf("%s",v);
// 	//  s = get_next_line(i);
// 	//  printf("%s",s);
// 	free (s);
// }