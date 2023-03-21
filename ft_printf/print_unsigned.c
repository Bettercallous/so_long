/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 00:34:16 by oubelhaj          #+#    #+#             */
/*   Updated: 2022/11/05 03:09:40 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int n, int *count)
{
	if (n > 9)
	{
		print_unsigned(n / 10, count);
		print_unsigned(n % 10, count);
	}
	else
		ft_putchar(n + 48, count);
}
