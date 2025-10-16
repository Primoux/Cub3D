#include "cub3d.h"

int	init_texture(t_data *data)
{
	data->texture = ft_calloc(1, sizeof(t_texture));
	if (!data->texture)
		return (1);
	data->texture->n_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->n_wall)
		return (1);
	data->texture->s_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->s_wall)
		return (1);
	data->texture->e_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->e_wall)
		return (1);
	data->texture->w_wall = ft_calloc(1, sizeof(t_img));
	if (!data->texture->w_wall)
		return (1);
	return (0);
}
