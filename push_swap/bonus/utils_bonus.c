/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:17:44 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/11 17:05:53 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	int_to_t_stack_a(char **argv, t_stack **a)
{
	t_node (*new_t_node);
	t_node (*current);
	int (*int_arr), (i), (count);
	count = 0;
	int_arr = to_int(argv, &count);
	i = 0;
	current = NULL;
	while (i < count)
	{
		new_t_node = malloc(sizeof(t_node));
		if (!new_t_node)
			return ;
		new_t_node->value = int_arr[i];
		new_t_node->next = NULL;
		if (!(*a)->top)
			(*a)->top = new_t_node;
		else
			current->next = new_t_node;
		current = new_t_node;
		(*a)->size++;
		i++;
	}
	free (int_arr);
}

void	free_t_stack(t_stack **a, t_stack **b)
{
	t_node (*current);
	t_node (*tmp);
	if (*a)
	{
		current = (*a)->top;
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		free(*a);
	}
	if (*b)
	{
		current = (*b)->top;
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		free(*b);
	}
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
