/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:15:35 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/11 03:49:24 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *a)
{
	t_node	*tmp;
	t_node	*current;

	if (!a || !a->top || !a->top->next)
		return ;
	current = a->top;
	while (current->next)
		current = current->next;
	tmp = a->top;
	a->top = tmp->next;
	current->next = tmp;
	tmp->next = NULL;
	write (1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*tmp;
	t_node	*current;

	if (!b->top || !b->top->next)
		return ;
	current = b->top;
	while (current->next)
		current = current->next;
	tmp = b->top;
	b->top = tmp->next;
	current->next = tmp;
	tmp->next = NULL;
	write (1, "rb\n", 3);
}

void	rra(t_stack *a)
{
	t_node	*last;
	t_node	*before_last;

	if (!a || !a->top || !a->top->next)
		return ;
	before_last = a->top;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = a->top;
	a->top = last;
	write (1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*last;
	t_node	*before_last;

	if (!b || !b->top || !b->top->next)
		return ;
	before_last = b->top;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = b->top;
	b->top = last;
	write (1, "rrb\n", 4);
}
