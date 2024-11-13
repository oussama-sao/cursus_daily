/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:14:18 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/12 15:52:07 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	count_words(char const *s, char c)
{
	size_t	i;
	int		in_word;
	size_t	count;

	in_word = 0;
	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

char	*get_words(const char *s, char c, size_t *start)
{
	char	*word;
	size_t	j;
	size_t	len;

	if (!s || !start)
		return (NULL);
	len = 0;
	while (s[*start] && s[*start] == c)
		(*start)++;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	if (len == 0)
		return (NULL);
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[*start];
		(*start)++;
		j++;
	}
	word[j] = '\0';
	return (word);
}

void	free_all(char **tab, size_t	i)
{
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	count;
	size_t	start;

	start = 0;
	i = 0;
	count = count_words(s, c);
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	while (i < count)
	{
		tab[i] = get_words(s, c, &start);
		if (tab[i] == NULL)
		{
			free_all(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

/*void test_ft_split(const char *s, char c, char **expected) {
    char **result = ft_split(s, c);
    int i = 0;

    // Compare each string in the result and expected arrays
    while (expected[i] != NULL && result[i] != NULL) {
        if (strcmp(result[i], expected[i]) != 0) {
printf("Test failed for input: \"%s\".Expected: \"%s\", got: \"%s\".\n"
			, s, expected[i], result[i]);
            // Free the result array before returning
            int j = 0;
            while (result[j]) {
                free(result[j]);
                j++;
            }
            free(result);
            return;
        }
        i++;
    }

    // Check if both arrays ended at the same time
    if (expected[i] != NULL || result[i] != NULL) {
 printf("Test failed for input: \"%s\". Expected: end of array, got: \"%s\".\n"
		, s, result[i] ? result[i] : "NULL");
    } else {
        printf("Test passed for input: \"%s\".\n", s);
    }

    // Free the result array
    if (result) {
        int j = 0;
        while (result[j]) {
            free(result[j]);
            j++;
        }
        free(result);
    }
}

int main() {
    test_ft_split("hello world", ' ', (char *[]){"hello", "world", NULL});
    test_ft_split("", ' ', (char *[]) {NULL});
test_ft_split("123,abc,456,def!", ',',
 (char *[]){"123", "abc", "456", "def!", NULL});
    test_ft_split("   ", ' ', (char *[]) {NULL});
    test_ft_split(",hello world,", ',', (char *[]){"hello world", NULL});
test_ft_split("word word word word",
 ' ', (char *[]){"word", "word", "word", "word", NULL});
    test_ft_split("wordwordwordword", ' ', (char *[]){"wordwordwordword", NULL});

    return 0;
}*/