/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:38:03 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:09:55 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

int	init_keys(t_cube *cube)
{
	cube->key = ft_calloc(1, sizeof(t_key));
	if (!cube->key)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	return (0);
}
