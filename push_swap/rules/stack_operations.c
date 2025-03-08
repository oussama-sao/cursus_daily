/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:15:35 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/08 02:35:41 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

stack	*init()
{
	stack	*s;

	s = malloc(sizeof(stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	return (s);
}

void	sa(stack *a)
{
	node	*tmp;
	if (!a->top || !a->top->next)
		return ;
	tmp = a->top->next;
	a->top->next = tmp->next;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "sa\n", 3);
}

void	sb(stack *b)
{
	node	*tmp;
	if (!b->top || !b->top->next)
		return ;
	tmp = b->top->next;
	b->top->next = tmp->next;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "sb\n", 3);
}

void	pa(stack **a, stack **b)
{
	node	*tmp;

	if (!(*b) || !(*b)->top)
		return ;
	tmp = (*b)->top;
	(*b)->top = tmp->next;
	tmp->next = (*a)->top;
	(*a)->top = tmp;
	(*a)->size++;
	(*b)->size--;
	write(1, "pa\n", 3);
}

void	pb(stack **b, stack **a)
{
	node	*tmp;

	if (!(*a) || !(*a)->top)
		return ;
	tmp = (*a)->top;
	(*a)->top = tmp->next;
	tmp->next = (*b)->top;
	(*b)->top = tmp;
	(*b)->size++;
	(*a)->size--;
	write(1, "pb\n", 3);	
}

void	ra(stack *a)
{
	node	*tmp;
	node	*current;

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

void	rb(stack *b)
{
	node	*tmp;
	node	*current;

	if (!b->top || !b->top->next)
		return ;
	current = b->top;
	while (current->next)
		current = current->next;
	tmp = b->top;
	b->top = tmp->next;
	current->next = tmp;
	tmp->next = NULL;
	write (1, "ra\n", 3);
}

void	rra(stack *a)
{
	node	*last;
	node	*before_last;

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

void	rrb(stack *b)
{
	node	*last;
	node	*before_last;

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
