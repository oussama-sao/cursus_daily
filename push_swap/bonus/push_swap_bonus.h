/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 00:12:16 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/12 00:02:05 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct t_node
{
	int				value;
	int				index;
	struct t_node	*next;
}	t_node;

typedef struct t_stack
{
	t_node	*top;
	int		size;
}	t_stack;

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
void		sa(t_stack *a);
void		sb(t_stack *b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);
int			is_sorted(t_stack *a);
void		int_to_t_stack_a(char **argv, t_stack **a);
void		free_t_stack(t_stack **a, t_stack **b);
t_stack		*init(void);
char		*ft_strjoing(char *s1, char *s2);
char		*ft_strjoin_and_free(char *s1, char *s2);
void		apply_rule(char *rule, t_stack **a, t_stack **b);
char		*gnl(int fd);

#endif
