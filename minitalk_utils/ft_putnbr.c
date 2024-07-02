/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:24:39 by rishibas          #+#    #+#             */
/*   Updated: 2024/05/22 13:27:10 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int d, int *count)
{
	int	value;

	if (d == -2147483648)
	{
		value = write(1, "-2147483648", 11);
		if (value == -1)
			return ;
		(*count) += value;
		return ;
	}
	if (d < 0)
	{
		ft_putchar('-', count);
		d *= -1;
	}
	if (d > 9)
		ft_putnbr(d / 10, count);
	ft_putchar(d % 10 + '0', count);
}
