/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:08:27 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/08 02:34:49 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_valid_number(char *str)
{
	int (found_digit), (j);
	j = 0;
	found_digit = 0;
	while (str[j])
	{
		while (str[j] == ' ')
			j++;
		if (str[j] == '+' || str[j] == '-')
			j++;
		if (!ft_isdigit(str[j]))
			return (0);
		while (ft_isdigit(str[j]))
		{
			found_digit = 1;
			j++;
		}
		if (!found_digit)
			return (0);
		if (str[j] && str[j] != ' ')
			return (0);
		while (str[j] == ' ')
			j++;
	}
	return (1);
}

int	is_empty(char **inputs)
{
	int	i;

	i = 1;
	while (inputs[i])
	{
		if (inputs[i][0] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

int	is_non_number(char **inputs)
{
	int (i), (j), (found_digit);
	i = 1;
	while (inputs[i])
	{
		j = 0;
		if (!is_valid_number(inputs[i]))
			return (-1);
		i++;
	}
	return (0);
}

int	is_within_int_range(char **inputs)
{
	char	**split;

	int (i), (j), (n), (error);
	i = 1;
	while (inputs[i])
	{
		j = 0;
		split = ft_split(inputs[i], ' ');
		if (!split)
			return (-1);
		while (split[j])
		{
			n = ft_atoi_safe(split[j], &error);
			if (error)
			{
				free_split(split);
				return (-1);
			}
			j++;
		}
		free_split(split);
		i++;
	}
	return (0);
}

int	is_duplicate(int *numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i])
	{
		j = i + 1;
		while (numbers[j])
		{
			if (numbers[i] == numbers[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
