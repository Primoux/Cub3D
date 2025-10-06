#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

int	parsing(t_data *data, char *argv);
int	check_name_and_access(t_data *data, char *argv);
int	read_and_fill_map_informations(t_data *data);
int	read_params(t_data *data);
int	read_map(t_data *data);

#endif
