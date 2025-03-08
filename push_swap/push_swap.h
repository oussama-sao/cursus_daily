/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:12:16 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/08 20:46:15 by oessaoud         ###   ########.fr       */
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
int			*to_int(char **arguments);
int			is_empty(char **inputs);
int			is_non_number(char **inputs);
int			is_within_int_range(char **inputs);
int			is_duplicate(int *numbers);
static int	is_valid_number(char *str);
void	sa(stack *a);
void	sb(stack *b);
void	pa(stack **a, stack **b);
void	pb(stack **b, stack **a);
void	ra(stack *a);
void	rb(stack *b);
void	rra(stack *a);
void	rrb(stack *b);

typedef struct node
{
	int	value;
	int	index;
	struct	node *next;
} node;

typedef struct stack
{
	node	*top;
	int		size;
	
} stack;

#endif