/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:12:41 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/06 19:55:16 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count(char const *s, const char c)
{
	size_t	i;
	size_t	count;
	char	*str;
	char	set[2];

	set[0] = c;
	set[1] = 0;
	count = 0;
	i = 0;
	str = ft_strtrim(s, set);
//	ft_strtrim(str, " \\n\\t\\v\\f\\r");

	while (str[i])
	{
		if (str[i] == c || str[i] = 0)
			count++;
		i++;
	}

	free(str);

	return (count);
}

// char	*words(const char *s, char c, size_t i)
// {
// 	char	*str;
// 	char	*word;
// 	size_t	j;
	
// 	str = (char *)s;
// 	ft_strtrim(str, c);
// 	while (str[i])
// 	{
// 		j = 0;
// 		if (str[i] == c)
// 			while (str[i])
// 			{
// 				word[j++] = str[i++];
// 				if (str[i] == c)
// 					break;	 
// 			}
// 	}
	
// }

char **ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	lent;

	if (!s)
		return (NULL);

	printf("%zu\n", count(s, c));
	// lent = ft_strlen(s);
	// tab = malloc(lent + 1);
	// if (!tab)
	// 	return (NULL);
	// while (i < count(s, c))
	// {
	// 	tab[i] = words(s, c, i);
	// 	i++;
	// }
	// tab[i] = NULL;
	return (NULL);
}

int main() {
	ft_split("hello world", ' ');
	ft_split("hello world", 'o');
	ft_split("           ", ' ');
	ft_split("           ", 'a');
	ft_split(" t t e f bh      ", ' ');
}