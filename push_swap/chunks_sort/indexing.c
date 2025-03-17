/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 02:36:43 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/11 03:49:24 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	indexing(t_stack **a)
{
	t_node	*current;
	t_node	*tmp;
	int		i;

	current = (*a)->top;
	while (current)
	{
		i = 0;
		tmp = (*a)->top;
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
