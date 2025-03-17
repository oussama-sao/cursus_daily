/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_rule_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:38:57 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/11 03:56:01 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	apply_rule(char *rule, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(rule, "sa\n", 3))
		sa(*a);
	else if (!ft_strncmp(rule, "sb\n", 3))
		sb(*b);
	else if (!ft_strncmp(rule, "ra\n", 3))
		ra(*a);
	else if (!ft_strncmp(rule, "rb\n", 3))
		rb(*b);
	else if (!ft_strncmp(rule, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(rule, "pb\n", 3))
		pb(b, a);
	else if (!ft_strncmp(rule, "rra\n", 4))
		rra(*a);
	else if (!ft_strncmp(rule, "rrb\n", 4))
		rrb(*b);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
}
	// else if (!ft_strncmp(rule, "sa\n", 3))
	// 	sa(a);
	// else if (!ft_strncmp(rule, "sa\n", 3))
	// 	sa(a);
	// else if (!ft_strncmp(rule, "sa\n", 3))
	// 	sa(a);
	// else if (!ft_strncmp(rule, "sa\n", 3))
	// 	sa(a);