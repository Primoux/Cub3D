#include "mlx_management.h"
#include "parsing.h"

void charge_img(t_data data)
{
	data.img->floor = mlx_xpm_file_to_image(data.mlx,
											"./textures/test_bloc.xpm", &data.map->x, &data.map->y);
}

void add_image(t_data data)
{

	data.map->y = 0;
	data.map->x = 0;
	while (data.map->map[data.map->x])
	{
		if (data.map->map[data.map->x][data.map->y] == '1')
		{
			mlx_put_image_to_window(data.mlx, data.win, data.img->floor, data.map->x, data.map->y);
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	init(&data);
	winner(data);

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./cub3d <map.cub>\n", 2);
		return (2);
	}
	if (init(&data) == 1 || parsing(&data, argv[1]) == 1)
	{
		free_all(&data);
		return (1);
	}
	add_image(data);
	// winner(data);
	free_all(&data);
}
