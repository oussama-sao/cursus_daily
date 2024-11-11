/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:59:22 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/11 11:11:54 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	len_int(int i)
{
	int	count;

	count = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		count ++;
		i *= -1;
	}
	while (i > 0)
	{
		count++;
		i /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
	{
	int		i;
	char	*number_in_char;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = len_int(n);
	i = len;
	number_in_char = malloc(sizeof(char) * (len + 1));
	if (!number_in_char)
		return (NULL);
	if (n < 0)
	{
		number_in_char[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		number_in_char[--i] = (n % 10) + '0';
		n /= 10;
	}
	number_in_char[len] = '\0';
	return (number_in_char);
}
/*
int main() {
    // Test cases
    int test_cases[] = {0, 42, -42, 2147483647, -2147483648, 123456, -123456};
    char *expected_results[] = {
        "0", // Test for zero
        "42", // Test for a positive number
        "-42", // Test for a negative number
        "2147483647", // Test for the maximum int value
        "-2147483648", // Test for the minimum int value
        "123456", // Test for a larger positive number
        "-123456" // Test for a larger negative number
    };

    size_t num_tests = sizeof(test_cases) / sizeof(test_cases[0]);

    // Iterate through the test cases
    for (size_t i = 0; i < num_tests; i++) {
        char *result = ft_itoa(test_cases[i]);
        if (result == NULL) {
            printf("Test %zu failed: ft_itoa returned NULL\n", i + 1);
        } else {
            if (strcmp(result, expected_results[i]) == 0) {
                printf("Test %zu passed\n", i + 1);
            } else {
                printf("Test %zu failed: expected '%s', got '%s'\n", 
                        i + 1, expected_results[i], result);
            }
            free(result); // Free the dynamically allocated memory
        }
    }

    return 0;
}*/