/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:38:03 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:38:04 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_keys(t_data *data)
{
	data->key = ft_calloc(1, sizeof(t_key));
	if (!data->key)
		return (1);
	return (0);
}
