/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:18:15 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 19:16:51 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*tab;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	tab = ft_calloc(len + 1, sizeof(char));
	if (tab == NULL)
		return (NULL);
	ft_memcpy(tab, src, len);
	return (tab);
}
