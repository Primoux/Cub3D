#include "cub3d.h"

static void init_data(t_data *data)
{
	data->mlx = NULL;
	data->map = NULL;
	data->win = NULL;
	data->img = NULL;
}

static void init_img(t_img *img)
{
	(void)img;
//	img->floor = NULL; ----SEG
//	img->wall = NULL; //en attendant 4 faces ----SEG
}

void	init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	init_data(data);
	init_img(data->img);
}