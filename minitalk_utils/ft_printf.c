/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 18:33:36 by rishibas          #+#    #+#             */
/*   Updated: 2024/05/22 13:34:16 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_convspec(char **str, va_list ap, int *count)
{
	(*str)++;
	if (**str == 'd' || **str == 'i')
		ft_putnbr(va_arg(ap, int), count);
	else if (**str == 'c')
		ft_putchar(va_arg(ap, int), count);
	else if (**str == 's')
		ft_putstr(va_arg(ap, char *), count);
	else if (**str == 'u')
		ft_put_unsigned_nbr(va_arg(ap, unsigned int), count);
	else if (**str == 'p')
		ft_putptr(va_arg(ap, void *), count);
	else if (**str == '%')
		ft_putchar('%', count);
	else if (**str == 'x')
		ft_puthex(va_arg(ap, unsigned int), 0, count);
	else if (**str == 'X')
		ft_puthex(va_arg(ap, unsigned int), 1, count);
	else
		(*count) -= -1;
}

void	print_str(char **str, int *count)
{
	int	value;

	if (**str == ' ')
		value = write(1, *str, 1);
	else
		value = write(1, *str, 1);
	if (value == -1)
		return ;
	(*count) += value;
}

int	ft_printf(const char *s, ...)
{
	int		count;
	char	*str;
	va_list	ap;

	va_start(ap, s);
	str = (char *)s;
	count = 0;
	while (*str)
	{
		if (*str == '%')
			find_convspec(&str, ap, &count);
		else
			print_str(&str, &count);
		str++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int	result;
//     int x;

//     x = 3;
// 	// printf("Hello");
// 	result = ft_printf("%d\nH", x);
// 	printf("ft_printf : %d\n", result);
// 	return (0);
// }