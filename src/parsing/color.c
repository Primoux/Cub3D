/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/26 17:48:56 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

static int	parse_color_format(char *color_str, t_color *color)
{
	char	*str;
	int		error;
	int		c;

	c = ft_atoi(color_str, &error);
	if (error || c < 0 || c > 255)
		return (1);
	color->red = c;
	str = ft_strchr(color_str, ',');
	if (!str || *(++str) == ',')
		return (1);
	c = ft_atoi(str, &error);
	if (error || c < 0 || c > 255)
		return (1);
	color->green = c;
	str = ft_strchr(str, ',');
	if (!str || *(++str) == ',')
		return (1);
	c = ft_atoi(str, &error);
	if (error || c < 0 || c > 255)
		return (1);
	color->blue = c;
	return (0);
}

static int	check_line_validity(char *line)
{
	int	nb_comma;

	nb_comma = 0;
	if (!ft_isdigit(*line))
		return (1);
	while (*line)
	{
		if (!ft_isdigit(*line) && *line != ',')
			return (1);
		if (*line == ',')
			nb_comma++;
		line++;
	}
	if (nb_comma > 2)
		return (1);
	return (0);
}

int	init_colors(t_cube *cube)
{
	if (check_line_validity(cube->map->floor_color) == 1)
		return (print_error("Invalid character in floor color line", __FILE__,
				__LINE__, RETURN_1));
	if (check_line_validity(cube->map->ceiling_color) == 1)
		return (print_error("Invalid character in ceiling color line", __FILE__,
				__LINE__, RETURN_1));
	if (parse_color_format(cube->map->ceiling_color,
			&cube->texture->ceiling) == 1)
		return (print_error("Invalid ceiling color value", __FILE__, __LINE__,
				RETURN_1));
	if (parse_color_format(cube->map->floor_color, &cube->texture->floor) == 1)
		return (print_error("Invalid floor color value", __FILE__, __LINE__,
				RETURN_1));
	return (0);
}
