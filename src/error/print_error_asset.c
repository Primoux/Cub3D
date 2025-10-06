#include "cub3d.h"

void	print_error_asset(t_data *data)
{
	if (!data->map->n_wall_path)
		ft_putstr_fd("Error: missing north wall texture (NO)\n", 2);
	if (!data->map->s_wall_path)
		ft_putstr_fd("Error: missing south wall texture (SO)\n", 2);
	if (!data->map->w_wall_path)
		ft_putstr_fd("Error: missing west wall texture (WE)\n", 2);
	if (!data->map->e_wall_path)
		ft_putstr_fd("Error: missing east wall texture (EA)\n", 2);
	if (!data->map->floor_color)
		ft_putstr_fd("Error: missing floor color (F)\n", 2);
	if (!data->map->sky_color)
		ft_putstr_fd("Error: missing ceiling color (C)\n", 2);
}
