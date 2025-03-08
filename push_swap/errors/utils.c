/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 23:43:27 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/08 02:34:54 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		i--;
		free (str[i]);
	}
	free (str);
}

int	ft_atoi_safe(const char *str, int *error)
{
	int (i), (signe);
	long (result);
	i = 0;
	signe = 1;
	result = 0;
	*error = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result * signe > INT_MAX || result * signe < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		i++;
	}
	return ((int)(result * signe));
}

int	count_numbers(char **arguments)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	count = 0;
	i = 1;
	while (arguments[i])
	{
		split = ft_split(arguments[i], ' ');
		j = 0;
		while (split[j])
			j++;
		count += j;
		i++;
	}
	free_split(split);
	return (count);
}

int	*to_int(char **arguments)
{
	int		*int_arr;
	int		i;
	int		j;
	int		z;
	char	**split_args;

	int_arr = malloc(count_numbers(arguments) * sizeof(int));
	if (!int_arr)
		return (NULL);
	i = 1;
	z = 0;
	while (arguments[i])
	{
		j = 0;
		split_args = ft_split(arguments[i], ' ');
		while (split_args[j])
		{
			int_arr[z] = ft_atoi(split_args[j]);
			j++;
			z++;
		}
		i++;
	}
	free_split(split_args);
	return (int_arr);
}
