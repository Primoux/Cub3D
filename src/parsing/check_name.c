/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:39 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/20 13:03:01 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"
#include <stdio.h>
#include <fcntl.h>

int	check_name_and_access(t_cube *cube, char *argv)
{
	size_t	length;

	if (!argv)
		return (1);
	length = ft_strlen(argv);
	if (length < 4 || ft_strncmp(&argv[length - 4], ".cub", 4) != 0)
		return (print_error("Argument must have a '.cub' extension"
				, __FILE__, __LINE__, RETURN_1));
	cube->map->fd_map = open(argv, O_RDONLY);
	if (cube->map->fd_map == -1)
		return (print_error("Can't open file, check read permission"
				, __FILE__, __LINE__, RETURN_1));
	return (0);
}
