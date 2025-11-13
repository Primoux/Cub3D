/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/11 17:06:38 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include <stdio.h>
#include <fcntl.h>

int	check_name_and_access(t_data *data, char *argv)
{
	size_t	length;

	if (!argv)
		return (1);
	length = ft_strlen(argv);
	if (length < 4 || ft_strncmp(&argv[length - 4], ".cub", 4) != 0)
	{
		ft_dprintf(2, "Error\nArgument must have a '.cub' extension\n");
		return (1);
	}
	data->map->fd_map = open(argv, O_RDONLY);
	if (data->map->fd_map == -1)
	{
		perror(argv);
		return (1);
	}
	return (0);
}
