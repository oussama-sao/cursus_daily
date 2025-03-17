/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_five_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 01:59:47 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/12 17:48:08 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->index == 1)
		sa(a);
}

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first < second && first < third && second > third)
	{
		rra(a);
		sa(a);
	}
	else if (first > second && first < third && second < third)
		sa(a);
	else if (first < second && first > third && second > third)
		rra(a);
	else if (first > second && first > third && second > third)
	{
		ra(a);
		sa(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	pb_smallest(a, b, 0);
	sort_three(*a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	pb_smallest(a, b, 0);
	pb_smallest(a, b, 1);
	sort_three(*a);
	pa(a, b);
	pa(a, b);
}

void	sort_under_five(t_stack **a, t_stack **b, int count)
{
	if (count == 2)
		sort_two(*a);
	else if (count == 3)
		sort_three(*a);
	else if (count == 4)
		sort_four(a, b);
	else if (count == 5)
		sort_five(a, b);
}
