/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:01:18 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/11 03:48:35 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_t_node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_t_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_t_node;
	}
	*lst = NULL;
}
