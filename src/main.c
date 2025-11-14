/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:51:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/14 16:57:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"
#include "memory.h"
#include "utils.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: ./cub3d <map.cub>\n");
		return (2);
	}
	if (init(&cube) != 0 || parsing(&cube, argv[1]) != 0
		|| init_colors(&cube) != 0 || init_mlx(&cube) != 0)
	{
		free_all(&cube);
		return (1);
	}
	winner(&cube);
	free_all(&cube);
	return (0);
}
