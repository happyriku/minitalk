/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:30:39 by rishibas          #+#    #+#             */
/*   Updated: 2024/06/14 14:38:08 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler1(int bit)
{
	static int				count;
	static unsigned char	c;

	if (bit == SIGUSR2)
		c = c << 1 | 1;
	else if (bit == SIGUSR1)
		c = c << 1 | 0;
	count++;
	if (count == 8)
	{
		ft_printf("%c", c);
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid value : %d\n", pid);
	signal(SIGUSR1, handler1);
	signal(SIGUSR2, handler1);
	while (1)
		pause();
	return (0);
}
