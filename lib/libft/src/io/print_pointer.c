/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:14:41 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/07 23:53:28 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	print_pointer(int fd, void *ptr)
{
	if (!ptr)
		return (write(fd, "(nil)", 5));
	else
	{
		return (write(fd, "0x", 2) + print_hexa(fd, (unsigned long)ptr));
	}
}

int	print_hexa(int fd, unsigned long n)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 16)
		return (ft_putchar_fd(symbols[n], fd));
	else
	{
		count = print_hexa(fd, n / 16);
		return (count + print_hexa(fd, n % 16));
	}
}
