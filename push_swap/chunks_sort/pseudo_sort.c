/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:36:24 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/11 16:42:47 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_start(int *start, int *end, t_stack **a, t_node **current)
{
	*current = (*a)->top;
	*start = 0;
	if ((*a)->size >= 6 && (*a)->size <= 100)
		*end = (*a)->size / 6;
	else if ((*a)->size > 100)
		*end = (*a)->size / 13;
}

void	fill_t_stack_b(t_stack **a, t_stack **b)
{
	t_node (*current);
	int (start), (end);
	init_start(&start, &end, a, &current);
	current = (*a)->top;
	while ((*a)->top)
	{
		if ((*a)->top->index < start)
		{
			pb(b, a);
			rb(*b);
			start++;
			end++;
		}
		else if ((*a)->top->index >= start && (*a)->top->index <= end)
		{
			pb(b, a);
			if ((*b)->top && (*b)->top->next
				&& (*b)->top->index < (*b)->top->next->index)
				sb(*b);
			start++;
			end++;
		}
		else
			ra(*a);
	}
}

void	final_t_stack_a(t_stack **a, t_stack **b)
{
	int (i);
	t_node (*current);
	while ((*b)->top)
	{
		current = (*b)->top;
		i = 0;
		while (current)
		{
			if (current->index == (*b)->size - 1)
				break ;
			i++;
			current = current->next;
		}
		if (i < (*b)->size / 2)
		{
			while (i--)
				rb(*b);
		}
		else
		{
			while (i++ <= (*b)->size - 1)
				rrb(*b);
		}
		pa(a, b);
	}
}
