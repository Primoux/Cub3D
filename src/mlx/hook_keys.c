#define _GNU_SOURCE
#include "cub3d.h"
#include "mlx_management.h"

int	close_window(t_data *data)
{
	free_all(data);
	exit(0);
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
	if (keycode == XK_Shift_L)
		data->key->shift_l_key = true;
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
	if (keycode == XK_Shift_L)
		data->key->shift_l_key = false;
}

int	handle_press_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s || keycode == XK_d
		|| keycode == XK_w || keycode == XK_Left || keycode == XK_Right
		|| keycode == XK_Tab || keycode == XK_Shift_L)
		press_key(data, keycode);
	return (0);
}

int	handle_release_key(int keycode, t_data *data)
{
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s || keycode == XK_d
		|| keycode == XK_w || keycode == XK_Left || keycode == XK_Right
		|| keycode == XK_Tab || keycode == XK_Shift_L)
		release_key(data, keycode);
	return (0);
}
