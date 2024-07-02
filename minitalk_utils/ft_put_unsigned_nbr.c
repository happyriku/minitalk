/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 17:16:28 by rishibas          #+#    #+#             */
/*   Updated: 2024/05/15 21:02:19 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_nbr(size_t num, int *count)
{
	if (num > 9)
		ft_putnbr(num / 10, count);
	ft_putchar(num % 10 + '0', count);
}
