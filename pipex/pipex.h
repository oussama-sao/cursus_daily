/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:35:51 by oessaoud          #+#    #+#             */
/*   Updated: 2025/02/25 14:44:52 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libft/libft.h"

void	ft_put_multi_str(char *s1, char *s2, char *s3, int fd);
void	free_split(char **split);
char	*ft_strjoin_all(char *str1, char *str2);
void	child1(int pipefd[2], char *infile, char *cmd, char **envp);
void	child2(int pipefd[2], char *outfile, char *cmd, char **envp);
void	execute(char *cmd, char **envp);

#endif