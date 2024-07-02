/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishibas <rishibas@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:02:21 by rishibas          #+#    #+#             */
/*   Updated: 2024/05/15 20:57:37 by rishibas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *s, ...);
void	ft_putstr(char *s, int *count);
void	ft_putnbr(int d, int *count);
void	ft_putchar(char c, int *count);
void	ft_put_unsigned_nbr(size_t num, int *count);
void	ft_putptr(void	*ptr, int *count);
size_t	ft_puthex(unsigned long num, int flag, int *count);

#endif
