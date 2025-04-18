/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:12:16 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/12 17:48:33 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

int			check_error(int argc, char **argv);
int			print_error(void);
void		free_split(char **str);
int			ft_atoi_safe(const char *str, int *error);
int			count_numbers(char **arguments);
int			*to_int(char **arguments, int *count);
int			is_empty(char **inputs);
int			is_non_number(char **inputs);
int			is_within_int_range(char **inputs);
int			is_duplicate(int *numbers, int count);
void		ready_to_sort(char **inputs);

typedef struct node
{
	int			value;
	int			index;
	struct node	*next;
}	t_node;

typedef struct stack
{
	t_node	*top;
	int		size;
}	t_stack;

void		sa(t_stack *a);
void		sb(t_stack *b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		fill_t_stack_b(t_stack **a, t_stack **b);
void		indexing(t_stack **a);
int			is_sorted(t_stack *a);
void		int_to_t_stack_a(char **argv, t_stack **a);
void		final_t_stack_a(t_stack **a, t_stack **b);
void		free_t_stack(t_stack **s);
t_stack		*init(void);
void		sort_under_five(t_stack **a, t_stack **b, int count);
void		pb_smallest(t_stack **a, t_stack **b, int index);

#endif