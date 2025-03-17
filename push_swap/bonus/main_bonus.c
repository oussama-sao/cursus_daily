/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 01:03:09 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/12 19:50:25 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	read_and_execute(t_list **lst, t_stack **a, t_stack **b)
{
	char	*rule;
	t_list	*current;

	while (1)
	{
		rule = gnl(0);
		if (rule == NULL)
			break ;
		ft_lstadd_back(lst, ft_lstnew(rule));
	}
	current = *lst;
	while (current)
	{
		apply_rule(current->content, a, b);
		current = current->next;
	}
	ft_lstclear(lst, free);
}

int	main(int argc, char **argv)
{
	t_list	*head;

	head = NULL;
	t_stack (*a);
	t_stack (*b);
	if (check_error(argc, argv) == -1)
		return (print_error());
	a = init();
	b = init();
	int_to_t_stack_a(argv, &a);
	read_and_execute(&head, &a, &b);
	if (is_sorted(a) && b->top == NULL)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	free_t_stack(&a, &b);
	return (0);
}
