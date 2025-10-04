#include "cub3d.h"

void init_data(t_data *data)
{
	data->mlx = NULL;
	data->map = NULL;
}

void init_img(t_img img)
{
	img.floor = NULL;
	img.wall = NULL; //en attendant les 4 faces
}

void	init(t_data *data)
{
	init_data(data);
	init_img(data->img);
}