/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:38:00 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:08:25 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

int	init_map(t_cube *cube)
{
	cube->map = ft_calloc(1, sizeof(t_map));
	if (!cube->map)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	return (0);
}
