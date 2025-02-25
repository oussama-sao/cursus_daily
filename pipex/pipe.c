/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:29:46 by oessaoud          #+#    #+#             */
/*   Updated: 2025/02/25 14:51:05 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*getpath(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (envp && ft_strncmp("PATH=", envp[i], 5) != 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin_all(paths[i], cmd);
		if (access(path, F_OK | X_OK) == 0)
		{
			free_split (paths);
			return (path);
		}
		free (path);
		i++;
	}
	free_split (paths);
	return (NULL);
}

char	*handle_path_cases(char *cmd, char **envp)
{
	char	*path;

	if (cmd[0] == '/' || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (access(cmd, F_OK | X_OK) == 0)
			return (ft_strdup(cmd));
	}
	path = getpath(cmd, envp);
	return (path);
}

void	execute(char *cmd, char **envp)
{
	char	**arguments;
	char	*fullpath;

	arguments = ft_split(cmd, ' ');
	if (!arguments || !arguments[0] || !arguments[0][0])
	{
		ft_putstr_fd("zsh: command not found: \n", 2);
		free_split(arguments);
		exit (127);
	}
	fullpath = handle_path_cases(arguments[0], envp);
	if (!fullpath)
	{
		ft_put_multi_str("zsh: command not found: ", arguments[0], NULL, 2);
		free_split (arguments);
		exit (127);
	}
	execve(fullpath, arguments, envp);
	ft_put_multi_str(strerror(errno), ": ", arguments[0], 2);
	if (fullpath != arguments[0])
		free (fullpath);
	free_split (arguments);
	exit (1);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];

	if (argc != 5)
	{
		perror("command format or arguments number is not correct");
		return (1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("creating pipe error!");
		return (1);
	}
	pid1 = fork();
	if (pid1 == 0)
		child1(pipefd, argv[1], argv[2], envp);
	pid2 = fork();
	if (pid2 == 0)
		child2(pipefd, argv[4], argv[3], envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
