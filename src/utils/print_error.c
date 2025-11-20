/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:44:20 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/20 12:48:30 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	print_error(char *str, char *file, int line, int ret)
{
	ft_dprintf(2, ERROR_MSG "%s (error msg in %s line %d)\n", str, file, line);
	return (ret);
}
