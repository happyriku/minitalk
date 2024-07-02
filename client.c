/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:30:29 by rishibas          #+#    #+#             */
/*   Updated: 2024/06/14 14:38:01 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_to_signal(pid_t pid, char octet)
{
	int				i;
	int				result;
	unsigned char	bit;

	bit = (unsigned char)octet;
	i = 8;
	while (i--)
	{
		if ((bit & 128) == 0)
			result = kill(pid, SIGUSR1);
		else if ((bit & 128) == 128)
			result = kill(pid, SIGUSR2);
		if (result == -1)
			return (1);
		bit = bit << 1;
		usleep(100);
	}
	return (0);
}

int	check_pid_is_natural(char *pid)
{
	int	i;

	i = 0;
	if (pid[0] == '-' || pid[0] == '0')
		return (1);
	while (pid[i])
	{
		if (!('0' <= pid[i] && pid[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		result;
	char	*message;
	pid_t	pid;

	if (argc != 3 || check_pid_is_natural(argv[1]) == 1)
		return (0);
	message = argv[2];
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (0);
	i = -1;
	while (message[++i])
	{
		result = send_to_signal(pid, message[i]);
		if (result == 1)
			return (0);
	}
	return (0);
}
