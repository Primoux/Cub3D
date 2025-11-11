/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:51:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/11 14:49:57 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "init.h"
#include "memory.h"
#include "utils.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: ./cub3d <map.cub>\n");
		return (2);
	}
	if (init(&data) != 0 || parsing(&data, argv[1]) != 0
		|| init_colors(&data) != 0 || init_mlx(&data) != 0)
	{
		free_all(&data);
		return (1);
	}
	winner(&data);
	free_all(&data);
	return (0);
}
