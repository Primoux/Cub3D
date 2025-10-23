/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:52:03 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/23 18:25:22 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_management.h"
#include <stdbool.h>

static void	handle_key(bool *key, t_mod_key mod, t_key_action action)
{
	if (mod == HOLD_MOD)
	{
		if (action == PRESS_ACTION)
			*key = true;
		else
			*key = false;
	}
	else
	{
		if (*key == false)
			*key = true;
		else
			*key = false;
	}
}

void	press_key(t_data *data, int keycode)
{
	if (keycode == XK_w)
		handle_key(&data->key->w_key, HOLD_MOD, PRESS_ACTION);
	if (keycode == XK_a)
		handle_key(&data->key->a_key, HOLD_MOD, PRESS_ACTION);
	if (keycode == XK_s)
		handle_key(&data->key->s_key, HOLD_MOD, PRESS_ACTION);
	if (keycode == XK_d)
		handle_key(&data->key->d_key, HOLD_MOD, PRESS_ACTION);
	if (keycode == XK_Left)
		handle_key(&data->key->left_key, HOLD_MOD, PRESS_ACTION);
	if (keycode == XK_Right)
		handle_key(&data->key->right_key, HOLD_MOD, PRESS_ACTION);
	if (keycode == XK_Shift_L)
		handle_key(&data->key->shift_l_key, HOLD_MOD, PRESS_ACTION);
	if (keycode == XK_Tab)
		handle_key(&data->key->tab_key, PRESS_MOD, PRESS_ACTION);
	if (keycode == XK_f)
		handle_key(&data->key->f_key, PRESS_MOD, PRESS_ACTION);
}

void	release_key(t_data *data, int keycode)
{
	if (keycode == XK_w)
		handle_key(&data->key->w_key, HOLD_MOD, RELEASE_ACTION);
	if (keycode == XK_a)
		handle_key(&data->key->a_key, HOLD_MOD, RELEASE_ACTION);
	if (keycode == XK_s)
		handle_key(&data->key->s_key, HOLD_MOD, RELEASE_ACTION);
	if (keycode == XK_d)
		handle_key(&data->key->d_key, HOLD_MOD, RELEASE_ACTION);
	if (keycode == XK_Left)
		handle_key(&data->key->left_key, HOLD_MOD, RELEASE_ACTION);
	if (keycode == XK_Right)
		handle_key(&data->key->right_key, HOLD_MOD, RELEASE_ACTION);
	if (keycode == XK_Shift_L)
	{
		handle_key(&data->key->shift_l_key, HOLD_MOD, RELEASE_ACTION);
		data->ray->rad_fov = (FOV) * (M_PI / 180);
	}
}

int	handle_press_key(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_w || keycode == XK_a || keycode == XK_s || keycode == XK_d
		|| keycode == XK_w || keycode == XK_Left || keycode == XK_Right
		|| keycode == XK_Tab || keycode == XK_Shift_L || keycode == XK_f)
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
