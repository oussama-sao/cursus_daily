/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:46:45 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/12 17:50:03 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ready_to_sort(char **inputs)
{
	t_stack	*a;
	t_stack	*b;
	int		count;

	count = count_numbers(inputs);
	a = init();
	b = init();
	int_to_t_stack_a(inputs, &a);
	if (is_sorted(a))
		return (free_t_stack(&a), free_t_stack(&b));
	indexing(&a);
	if (count <= 5)
		return (sort_under_five(&a, &b, count),
			free_t_stack(&a), free_t_stack(&b));
	fill_t_stack_b(&a, &b);
	final_t_stack_a(&a, &b);
	free_t_stack(&a);
	free_t_stack(&b);
}
