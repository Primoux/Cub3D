/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:54:41 by enchevri          #+#    #+#             */
/*   Updated: 2025/11/20 11:02:38 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
# define VALID_CHARS "01 NSEW\t"
# define MAX_MAP_SIZE 200000

int	parsing(t_cube *cube, char *argv);
int	check_name_and_access(t_cube *cube, char *argv);
int	read_and_fill_map_informations(t_cube *cube);
int	read_params(t_cube *cube);
int	read_map(t_cube *cube);
int	check_map_validity(t_cube *cube, char **map);
int	char_compare(char c);
int	check_char(t_cube *cube, char **map, int *y, int *x);
int	launch_flood_fill(t_cube *cube);

#endif
