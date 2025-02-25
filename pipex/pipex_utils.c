/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:38:53 by oessaoud          #+#    #+#             */
/*   Updated: 2025/02/24 22:39:22 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_put_multi_str(char *s1, char *s2, char *s3, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putstr_fd(s2, fd);
	ft_putstr_fd(s3, fd);
	ft_putchar_fd('\n', fd);
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split && split[i])
	{
		free (split[i]);
		i++;
	}
	free (split);
}

char	*ft_strjoin_all(char *str1, char *str2)
{
	char	*tmp;
	char	*path;

	tmp = ft_strjoin("/", str2);
	path = ft_strjoin(str1, tmp);
	free (tmp);
	return (path);
}
