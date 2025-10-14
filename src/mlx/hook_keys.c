#include "cub3d.h"
#include "mlx_management.h"

int	close_window(t_data *data)
{
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
		player->px = new_x;
		player->py = new_y;
	}
}

int	move_player(t_data *data)
{
	double	new_x;
	double	new_y;

	if (data->key->w_key == true)
	{
		new_x = data->player->px + cos(data->player->angle) * MOVE_SPEED;
		new_y = data->player->py + sin(data->player->angle) * MOVE_SPEED;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (data->key->s_key == true)
	{
		new_x = data->player->px - cos(data->player->angle) * MOVE_SPEED;
		new_y = data->player->py - sin(data->player->angle) * MOVE_SPEED;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (data->key->d_key == true)
	{
		new_x = data->player->px + cos(data->player->angle + M_PI / 2)
			* MOVE_SPEED;
		new_y = data->player->py + sin(data->player->angle + M_PI / 2)
			* MOVE_SPEED;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (data->key->a_key == true)
	{
		new_x = data->player->px - cos(data->player->angle + M_PI / 2)
			* MOVE_SPEED;
		new_y = data->player->py - sin(data->player->angle + M_PI / 2)
			* MOVE_SPEED;
		check_colision(data->player, data->map, new_y, new_x);
	}
	if (data->key->left_key == true)
		data->player->angle -= ANGLE_SPEED;
	if (data->key->right_key == true)
		data->player->angle += ANGLE_SPEED;
	norm_angle(&data->player->angle);
	raycaster(data);
	imaginer(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	press_key(t_data *data, int keycode)
{
	if (keycode == XK_w)
		data->key->w_key = true;
	if (keycode == XK_a)
		data->key->a_key = true;
	if (keycode == XK_s)
		data->key->s_key = true;
	if (keycode == XK_d)
		data->key->d_key = true;
	if (keycode == XK_Left)
		data->key->left_key = true;
	if (keycode == XK_Right)
		data->key->right_key = true;
	if (keycode == XK_Tab)
	{
		if (data->key->tab_key == false)
			data->key->tab_key = true;
		else
			data->key->tab_key = false;
	}
}

void	release_key(t_data *data, int keycode)
{
	if (keycode == XK_w)
		data->key->w_key = false;
	if (keycode == XK_a)
		data->key->a_key = false;
	if (keycode == XK_s)
		data->key->s_key = false;
	if (keycode == XK_d)
		data->key->d_key = false;
	if (keycode == XK_Left)
		data->key->left_key = false;
	if (keycode == XK_Right)
		data->key->right_key = false;
}

int	handle_press_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s || keycode == XK_d
		|| keycode == XK_w || keycode == XK_Left || keycode == XK_Right || keycode == XK_Tab)
		press_key(data, keycode);
	return (0);
}

int	handle_release_key(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s || keycode == XK_d
		|| keycode == XK_w || keycode == XK_Left || keycode == XK_Right|| keycode == XK_Tab)
		release_key(data, keycode);
	return (0);
}
