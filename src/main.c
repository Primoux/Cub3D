#include "cub3d.h"
#include "mlx.h"
#include "parsing.h"
#include <X11/keysym.h>

void	winner(t_data data)
{
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WEIGHT, HEIGHT, "prout");
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
}

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
		ft_putstr_fd("Bad usage", 2);
		return (2);
	}
	if (init(&data) != 0)
	{
		ft_putstr_fd("init failed\n", 2);
		free_all(&data);
		return (1);
	}
	if (parsing(&data, argv[1]) == 1)
	{
		free_all(&data);
		return (1);
	}
	add_image(data);
	// winner(data);
	free_all(&data);
}
