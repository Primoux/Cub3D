/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:37:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:10:04 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

int	init_destroy(t_cube *cube)
{
	cube->destroy = ft_calloc(1, sizeof(t_destroy));
	if (!cube->destroy)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	cube->destroy->begin_destroy = -1.0;
	cube->destroy->x = -1;
	cube->destroy->y = -1;
	return (0);
}
