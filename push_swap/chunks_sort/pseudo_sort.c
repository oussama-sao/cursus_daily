/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudo_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:36:24 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/08 21:29:12 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init(int *start, int *end, stack **a, node *current)
{
	node	*current;
	int		start;
	int		end;

	current = (*a)->top;
	start = 0;
	if ((*a)->size >= 6 && (*a)->size <= 100)
		end = (*a)->size / 6;
	else if ((*a)->size > 100)
		end = (*a)->size / 13;
}

void	fill_stack_b(stack **a, stack **b)
{
	node (*current);
	int (start), (end);
	init(&start, &end, current, (*a));
	while (*a)
	{
		if (current->index < start)
		{
			pb(b, a);
			rb(*b);
			start++;
			end++;
		}
		else if (current->index >= start && current->index <= end)
		{
			pb(b, a);
			if ((*b) && (*b)->top && (*b)->top->next
				&& (*b)->top->index < (*b)->top->next->index)
				sb(*b);
			start++;
			end++;
		}
		else
			ra(*a);
	}
}
