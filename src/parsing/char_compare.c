/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_compare.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:36 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:52:38 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	char_compare(char c)
{
	size_t	i;

	i = 0;
	while (VALID_CHARS[i])
	{
		if (VALID_CHARS[i] == c)
			return (0);
		i++;
	}
	return (1);
}
