/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:19:51 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/12 17:50:25 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	free_t_stack(t_stack **s)
{
	t_node (*current);
	t_node (*tmp);
	if (*s)
	{
		current = (*s)->top;
		while (current)
		{
			tmp = current->next;
			free(current);
			current = tmp;
		}
		free(*s);
	}
}

void	pb_smallest(t_stack **a, t_stack **b, int index)
{
	t_node	*current;
	int		i;

	i = 0;
	current = (*a)->top;
	while (current)
	{
		if (current->index == index)
			break ;
		i++;
		current = current->next;
	}
	if (i < (*a)->size / 2)
	{
		while (i--)
			ra(*a);
	}
	else
	{
		while (i++ <= (*a)->size -1)
			rra(*a);
	}
	pb(b, a);
}
