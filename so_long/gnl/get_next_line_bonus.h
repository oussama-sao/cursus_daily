/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:40:49 by oessaoud          #+#    #+#             */
/*   Updated: 2025/04/06 15:53:27 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 41
# endif

# ifndef MAX_FD
#  define MAX_FD 1000
# endif

char	*get_next_line(int fd);
char	*ft_strjoing(char *s1, char *s2);
char	*ft_strjoin_and_free(char *s1, char *s2);

#endif