/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:51:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/20 13:03:55 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"
#include "memory.h"
#include "parsing.h"
#include "utils.h"

int	main(int argc, char **argv)
{
	t_cube	cube;

	if (argc != 2)
		return (print_error("Usage: ./cub3d <map.cub>", __FILE__, __LINE__,
				RETURN_2));
	if (init(&cube) != 0 || parsing(&cube, argv[1]) != 0
		|| init_colors(&cube) != 0 || init_mlx(&cube) != 0)
	{
		free_all(&cube);
		return (1);
	}
	windowser(&cube);
	return (0);
}
