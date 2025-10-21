/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:52:46 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_color_format(char *color_str, t_color *color, int *error)
{
	int		red;
	int		green;
	int		blue;
	char	*str;

	red = ft_atoi(color_str, error);
	if (*error || red < 0 || red > 255)
		return (1);
	str = ft_strchr(color_str, ',');
	if (!str)
		return (1);
	green = ft_atoi(++str, error);
	if (*error || green < 0 || green > 255)
		return (1);
	str = ft_strchr(str, ',');
	if (!str)
		return (1);
	blue = ft_atoi(++str, error);
	if (*error || blue < 0 || blue > 255)
		return (1);
	color->red = red;
	color->green = green;
	color->blue = blue;
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
