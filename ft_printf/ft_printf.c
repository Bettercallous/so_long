/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:53:28 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/07 09:46:25 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_c(char c, va_list p, int *count)
{
	if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(p, int), count);
	else if (c == 'c')
		ft_putchar(va_arg(p, int), count);
	else if (c == 's')
		ft_putstr(va_arg(p, char *), count);
	else if (c == 'x' || c == 'X')
		print_hex(va_arg(p, unsigned int), c, count);
	else if (c == 'p')
	{
		ft_putstr("0x", count);
		print_address(va_arg(p, unsigned long), count);
	}
	else if (c == 'u')
		print_unsigned(va_arg(p, unsigned int), count);
	else if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	p;

	i = 0;
	count = 0;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (count);
		else if (str[i] == '%')
		{
			i++;
			check_c(str[i], p, &count);
		}
		else
			ft_putchar(str[i], &count);
		i++;
	}
	va_end(p);
	return (count);
}
