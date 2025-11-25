/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:38:05 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/25 16:02:00 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

int	init_img(t_cube *cube)
{
	cube->img = ft_calloc(1, sizeof(t_img));
	if (!cube->img)
		return (print_error("ft_calloc failed", __FILE__, __LINE__, RETURN_1));
	return (0);
}
