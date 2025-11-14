/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"

static int	parse_color_format(char *color_str, t_color *color)
{
	char	*str;
	int		error;

	color->red = ft_atoi(color_str, &error);
	if (error || color->red < 0 || color->red > 255)
		return (1);
	str = ft_strchr(color_str, ',');
	if (!str || *(++str) == ',')
		return (1);
	color->green = ft_atoi(str, &error);
	if (error || color->green < 0 || color->green > 255)
		return (1);
	str = ft_strchr(str, ',');
	if (!str || *(++str) == ',')
		return (1);
	color->blue = ft_atoi(str, &error);
	if (error || color->blue < 0 || color->blue > 255)
		return (1);
	return (0);
}

static int	check_line_validity(char *line)
{
	int			i;
	int			y;
	const char	*good_char = {"0123456789,"};
	int			g_c_len;

	g_c_len = ft_strlen(good_char);
	i = 0;
	while (line[i])
	{
		y = 0;
		while (good_char[y])
		{
			if (good_char[y] == line[i])
				break ;
			y++;
		}
		if (y == g_c_len)
			return (1);
		i++;
	}
	return (0);
}

int	init_colors(t_cube *cube)
{
	if (check_line_validity(cube->map->floor_color) == 1
		|| check_line_validity(cube->map->ceiling_color) == 1)
	{
		ft_dprintf(2, "Error\nInvalid character in line\n");
		return (1);
	}
	if (parse_color_format(cube->map->ceiling_color,
			&cube->texture->ceiling) == 1)
	{
		ft_dprintf(2, "Error\nInvalid color values\n");
		return (1);
	}
	if (parse_color_format(cube->map->floor_color, &cube->texture->floor) == 1)
	{
		ft_dprintf(2, "Error\nInvalid color values\n");
		return (1);
	}
	return (0);
}
