/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 03:44:41 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/11 03:49:24 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	return (s);
}

void	sa(t_stack *a)
{
	t_node	*tmp;

	if (!a->top || !a->top->next)
		return ;
	tmp = a->top->next;
	a->top->next = tmp->next;
	tmp->next = a->top;
	a->top = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*tmp;

	if (!b->top || !b->top->next)
		return ;
	tmp = b->top->next;
	b->top->next = tmp->next;
	tmp->next = b->top;
	b->top = tmp;
	write(1, "sb\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_node	*tmp;

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

void	pb(t_stack **b, t_stack **a)
{
	t_node	*tmp;

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
