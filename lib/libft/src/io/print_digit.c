/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:36:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/26 18:12:39 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	print_digit(int fd, long n, int base, char c)
{
	int		count;
	char	*symbols;

	count = 0;
	if (c == 'd' || c == 'x' || c == 'u' || c == 'i')
		symbols = "0123456789abcdef";
	if (c == 'X')
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		count += write(1, "-", 1);
		return (print_digit(fd, -n, base, c) + count);
	}
	else if (n < base)
		return (ft_putchar_fd(symbols[n], fd));
	else
	{
		count = print_digit(fd, n / base, base, c);
		return (count + print_digit(fd, n % base, base, c));
	}
}
