/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:19:47 by rishibas          #+#    #+#             */
/*   Updated: 2024/05/21 21:38:07 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void	*ptr, int *count)
{
	size_t	num;
	int		value;

	if (ptr == NULL)
	{
		value = write(1, "0x0", 3);
		if (value == -1)
			return ;
		(*count) += value;
		return ;
	}
	value = write(1, "0x", 2);
	if (value == -1)
		return ;
	(*count) += value;
	num = (unsigned long)ptr;
	ft_puthex(num, 0, count);
}
