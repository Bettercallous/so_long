/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:03:23 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/07 08:43:18 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

void	ft_putnbr(int n, int *count);
void	ft_putchar(char c, int *count);
int		ft_printf(const char *str, ...);
void	ft_putstr(char *str, int *count);
void	print_unsigned(unsigned int n, int *count);
void	print_address(unsigned long nb, int *count);
void	print_hex(unsigned int n, char c, int *count);

#endif