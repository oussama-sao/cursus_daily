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

#include "get_next_line.h"

char	*get_text(int fd, char *text)
{
	int		i;
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
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
		text = ft_strjoin_and_free(text, buffer);
		if (!text)
		{
			free (buffer);
			return (NULL);
		}
	}
	free (buffer);
	return (text);
}

char	*get_line(char *text, int size)
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
	char	*rest;

	if (!text || !*text || !**text)
		return (NULL);
	i = 0;
	while ((*text)[i] && (*text)[i] != '\n')
		i++;
	len = i + ((*text)[i] == '\n');
	line = get_line(*text, len);
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
	static char	*text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = get_text(fd, text);
	if (!text || !*text)
	{
		free (text);	
		return (NULL);
	}
	line = next_line(&text);
	return (line);
}

int main()
{
	int i = open("file1.txt",O_RDONLY);
	int i2 = open("file2.txt",O_RDONLY);
	char *s = get_next_line(i);
	 printf("%s",s);
	char *s2 = get_next_line(i2);
	printf("+%s+",s2);
	char *k2 = get_next_line(i2);
 	printf("2%s2",k2);
	char *d2 = get_next_line(i2);
 	printf("%s",d2);
	char *c2 = get_next_line(i2);
 	printf("%s",c2);
	char *v2 = get_next_line(i2);
 	printf("%s",v2);
	char *b2 = get_next_line(i2);
	printf("%s",b2);
	char *k = get_next_line(i);
 	printf("%s",k);
	char *d = get_next_line(i);
 	printf("%s",d);
	char *c = get_next_line(i);
 	printf("%s",c);
	char *v = get_next_line(i);
 	printf("%s",v);
	char *b = get_next_line(i);
	printf("2%s",b);
}