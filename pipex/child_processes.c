/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:35:33 by oessaoud          #+#    #+#             */
/*   Updated: 2025/02/24 22:41:42 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int pipefd[2], char *infile, char *cmd, char **envp)
{
	int	fd;

	fd = open(infile, O_RDONLY);
	if (fd < 0)
	{
		ft_put_multi_str(strerror(errno), ": ", infile, 1);
		exit(1);
	}
	if (!cmd || !*cmd)
	{
		ft_put_multi_str("zsh: permission denied: ", NULL, NULL, 2);
		exit(126);
	}
	dup2(fd, 0);
	close(fd);
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	execute(cmd, envp);
}

void	child2(int pipefd[2], char *outfile, char *cmd, char **envp)
{
	int	fd;

	fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_put_multi_str(strerror(errno), ": ", outfile, 1);
		exit(1);
	}
	if (!cmd || !*cmd)
	{
		ft_put_multi_str("zsh: permission denied: ", NULL, NULL, 2);
		exit(126);
	}
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(fd, 1);
	close(fd);
	close(pipefd[1]);
	execute(cmd, envp);
}
