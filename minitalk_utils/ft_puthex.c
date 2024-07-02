/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:20:48 by rishibas          #+#    #+#             */
/*   Updated: 2024/05/15 21:00:38 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex(unsigned long num, int flag, int *count)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (flag == 1)
		hex = "0123456789ABCDEF";
	if (num >= 16)
		ft_puthex(num / 16, flag, count);
	ft_putchar(hex[num % 16], count);
	return (0);
}
