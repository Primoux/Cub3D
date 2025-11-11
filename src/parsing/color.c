/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/11 16:35:44 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

static int	parse_color_format(char *color_str, t_color *color, int *error)
{
	char	*str;

	color->red = ft_atoi(color_str, error);
	if (*error || color->red < 0 || color->red > 255)
		return (1);
	str = ft_strchr(color_str, ',');
	if (!str || *(++str) == ',')
		return (1);
	color->green = ft_atoi(str, error);
	if (*error || color->green < 0 || color->green > 255)
		return (1);
	str = ft_strchr(str, ',');
	if (!str || *(++str) == ',')
		return (1);
	color->blue = ft_atoi(str, error);
	if (*error || color->blue < 0 || color->blue > 255)
		return (1);
	return (0);
}

int	init_colors(t_data *data)
{
	int	error;

	error = 0;
	if (parse_color_format(data->map->ceiling_color, &data->texture->ceiling,
			&error) == 1)
	{
		ft_dprintf(2, "Error: Invalid color values\n");
		return (1);
	}
	if (parse_color_format(data->map->floor_color, &data->texture->floor,
			&error) == 1)
	{
		ft_dprintf(2, "Error: Invalid color values\n");
		return (1);
	}
	return (0);
}
