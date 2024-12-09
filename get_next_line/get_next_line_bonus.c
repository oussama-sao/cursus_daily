/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:45:34 by oessaoud          #+#    #+#             */
/*   Updated: 2024/12/07 20:57:42 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_text(int fd, char *text)
{
	int		i;
	char *buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free (buffer);
			free (text);
			return (NULL);
		}
		buffer[i] = '\0';
		text = ft_strjoin_and_free(text, buffer);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free (buffer);
	return (text);
}

char	*get_line2(char *text, int size)
{
	char	*line;
	int		i;

	i = 0;
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
	char	*rest;

	if (!text[size])
	{
		free (text);
		return (NULL);
	}
	rest = ft_strdup(text + size);
	free (text);
	return (rest);
}

char	*next_line(char **text)
{
	int		i;
	int		len;
	char	*line;

	if (!text || !*text || !**text)
		return (NULL);
	i = 0;
	while ((*text)[i] && (*text)[i] != '\n')
		i++;
	len = i + ((*text)[i] == '\n');
	line = get_line2(*text, len);
	if (!line)
	{
		free (text);
		return (NULL);
	}
	*text = get_rest(*text, len);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	text[fd] = get_text(fd, text[fd]);
	if (!text[fd] || !(*text[fd]))
	{
		if (text[fd])
		{
			free (text[fd]);
			text[fd] = NULL;
		}
		return (NULL);
	}
	line = next_line(&text[fd]);
	return (line);
}

// int main()
// {
// 	int fd1 = open("file1.txt", O_RDONLY);
// 	int fd2 = open("file2.txt", O_RDONLY);

// 	char *line1 = get_next_line(fd1);
// 	printf("File1: %s", line1);
// 	free(line1);

// 	char *line2 = get_next_line(fd2);
// 	printf("File2: %s", line2);
// 	free(line2);

// 	line1 = get_next_line(fd1);
// 	printf("File1: %s", line1);
// 	free(line1);

// 	line2 = get_next_line(fd2);
// 	printf("File2: %s", line2);
// 	free(line2);
// 	line1 = get_next_line(fd1);
// 	printf("File1: %s", line1);
// 	free(line1);

// 	line2 = get_next_line(fd2);
// 	printf("File2: %s", line2);
// 	free(line2);
// 	line1 = get_next_line(fd1);
// 	printf("File1: %s", line1);
// 	free(line1);

// 	line2 = get_next_line(fd2);
// 	printf("File2: %s", line2);
// 	free(line2);

// 	close(fd1);
// 	close(fd2);
// }