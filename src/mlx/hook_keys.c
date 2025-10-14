#include "cub3d.h"
#include "mlx_management.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->texture->floor);
	mlx_destroy_image(data->mlx, data->texture->wall);
	mlx_destroy_image(data->mlx, data->texture->perso_n);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_all(data);
	exit(0);
}

void	check_colision(t_player *player, t_map *map, double new_y, double new_x)
{
	int	tile_x;
	int	tile_y;

	tile_x = floor(new_x / TILE);
	tile_y = floor(new_y / TILE);
	if ((map->map[tile_y][tile_x] == '0' || map->map[tile_y][tile_x] == 'N'
			|| map->map[tile_y][tile_x] == 'S'
			|| map->map[tile_y][tile_x] == 'E'
			|| map->map[tile_y][tile_x] == 'W'))
	{
		ft_printf("(%s) C'est bon map->map[[%d][%d] = '%c'\n", __func__,
			tile_y, tile_x, map->map[tile_y][tile_x]);
		player->px = new_x;
		player->py = new_y;
	}
}

void	move_player(t_data *data, int keycode)
{
	double	new_x;
	double	new_y;

	if (keycode == XK_w)
	{
		new_x = data->player->px + cos(data->player->angle) * MOVE_SPEED;
		new_y = data->player->py + sin(data->player->angle) * MOVE_SPEED;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (keycode == XK_s)
	{
		new_x = data->player->px - cos(data->player->angle) * MOVE_SPEED;
		new_y = data->player->py - sin(data->player->angle) * MOVE_SPEED;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (keycode == XK_d)
	{
		new_x = data->player->px + cos(data->player->angle + M_PI / 2)
			* MOVE_SPEED;
		new_y = data->player->py + sin(data->player->angle + M_PI / 2)
			* MOVE_SPEED;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (keycode == XK_a)
	{
		new_x = data->player->px - cos(data->player->angle + M_PI / 2)
			* MOVE_SPEED;
		new_y = data->player->py - sin(data->player->angle + M_PI / 2)
			* MOVE_SPEED;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (keycode == XK_Left)
		data->player->angle -= ANGLE_SPEED;
	if (keycode == XK_Right)
		data->player->angle += ANGLE_SPEED;
	raycaster(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s || keycode == XK_d
		|| keycode == XK_w || keycode == XK_Left || keycode == XK_Right)
		move_player(data, keycode);
	return (0);
}
