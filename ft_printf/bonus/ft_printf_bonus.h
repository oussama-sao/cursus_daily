/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:40:46 by oessaoud          #+#    #+#             */
/*   Updated: 2025/01/22 18:22:37 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

void	ft_putchar_printf(char c, int *count);
void	ft_putstr_printf(char *str, int *count);
void	ft_putnbr_printf(int nbr, int *count);
void	ft_putnbr_u_printf(unsigned int nbr, int *count);
void	ft_putaddress_printf(void *ptr, int *count);
void	ft_puthexa_printf(unsigned long nbr, short isupper, int *count);
void	ft_putpourcent_printf(int *count);
int		ft_printf(const char *str, ...);

#endif
