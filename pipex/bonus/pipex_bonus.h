/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:09:56 by oessaoud          #+#    #+#             */
/*   Updated: 2025/02/25 14:53:42 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/libft.h"

void	middle_childs(int prev, int pipefd[2], char *cmd, char **envp);
void	last_child(int prev, char *outfile, char *cmd, char **envp);
void	creat_child(int *prev, int pipefd[2], char *cmd, char **envp);
void	ft_put_multi_str(char *s1, char *s2, char *s3, int fd);
void	free_split(char **split);
char	*ft_strjoin_all(char *str1, char *str2);
int		handle_error(char *msg, int return_value);
int		open_file(char *file, int flag, int mode);
void	execute(char *cmd, char **envp);

#endif
