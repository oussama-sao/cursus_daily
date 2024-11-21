/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessaoud <oessaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:40:46 by oessaoud          #+#    #+#             */
/*   Updated: 2024/11/21 21:43:46 by oessaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putchar_printf(char c);
int	ft_putstr_printf(char *str);
int	ft_putnbr_printf(int nbr);
int	ft_putnbr_u_printf(unsigned int nbr);
int	ft_putaddress_printf(void *ptr);
int	ft_puthexa_printf(unsigned long nbr, short isupper);
int	ft_putpourcent_printf(void);
int	ft_printf(const char *str, ...);

#endif
