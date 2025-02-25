/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_managment_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:09:28 by oessaoud          #+#    #+#             */
/*   Updated: 2025/02/25 14:46:33 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	middle_childs(int prev, int pipefd[2], char *cmd, char **envp)
{
	dup2(prev, 0);
	dup2(pipefd[1], 1);
	close(prev);
	close(pipefd[1]);
	close(pipefd[0]);
	execute(cmd, envp);
}

void	last_child(int prev, char *outfile, char *cmd, char **envp)
{
	int	fd;

	fd = open_file(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		fd = open("/dev/null", O_WRONLY);
	dup2(prev, 0);
	dup2(fd, 1);
	close(fd);
	close(prev);
	execute(cmd, envp);
}

void	creat_child(int *prev, int pipefd[2], char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		middle_childs(*prev, pipefd, cmd, envp);
	close(*prev);
	close(pipefd[1]);
	*prev = pipefd[0];
}
