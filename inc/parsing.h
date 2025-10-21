/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:54:41 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/21 21:54:45 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"
# define VALID_CHARS "01 NSEW\t"

int	parsing(t_data *data, char *argv);
int	check_name_and_access(t_data *data, char *argv);
int	read_and_fill_map_informations(t_data *data);
int	read_params(t_data *data);
int	read_map(t_data *data);
int	check_map_validity(t_data *data, char **map);
int	char_compare(char c);
int	check_char(t_data *data, char **map, int *y, int *x);
int	init_mlx(t_data *data);

#endif
