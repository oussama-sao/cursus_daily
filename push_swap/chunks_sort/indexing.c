/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:36:43 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/08 20:34:57 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	indexing(stack *s)
{
	node	*current;
	node	*tmp;
	int		i;

	current = s->top;
	while (current)
	{
		i = 0;
		tmp = s->top->next;
		while (tmp)
		{
			if (current->value > tmp->value)
				i++;
			tmp = tmp->next;
		}
		current->index = i;
		current = current->next;
	}
}
