/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:57:17 by oessaoud          #+#    #+#             */
/*   Updated: 2025/03/08 02:34:42 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_error(int argc, char **argv)
{
	int	*argv_to_int;

	if (argc < 2)
		exit (1);
	if (is_empty(argv) || is_non_number(argv) || is_within_int_range(argv))
		return (-1);
	argv_to_int = to_int(argv);
	if (!argv_to_int)
		return (-1);
	if (is_duplicate(argv_to_int))
		return (free(argv_to_int), -1);
	free(argv_to_int);
	return (0);
}
