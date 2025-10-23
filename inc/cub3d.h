/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:54:50 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/22 17:15:25 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FOV 60

// 1500 par 1000
// Dell
# define WIDTH 1920
# define HEIGHT 1080
//// Mac
// # define HEIGHT 2160
// # define WIDTH 3840

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_texture	t_texture;
typedef struct s_mlx		t_mlx;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;
typedef struct s_key		t_key;

typedef struct s_img
{
	void					*img;
	char					*addr;
	int						bpp;
	int						line_length;
	int						endian;
	int						width;
	int						height;

}							t_img;

typedef union u_color
{
	unsigned int			val;
	struct
	{
		uint8_t				blue;
		uint8_t				green;
		uint8_t				red;
		uint8_t				alpha;
	};
}							t_color;

struct						s_texture
{
	t_color					floor;
	t_color					ceiling;
	t_img					*n_wall;
	t_img					*s_wall;
	t_img					*w_wall;
	t_img					*e_wall;
};

struct						s_player
{
	double					px;
	double					py;
	float					rad;
	double					angle;
	double					last_frame_time;
};

struct						s_ray
{
	double					rx;
	double					ry;
	float					rad_fov;
	double					angle;
	double					ray_dist;
	double					rx_dist;
	double					ry_dist;
	char					flag;
	double					rwall_height;
	double					rwall_top;
	double					hit_x;
	double					hit_y;
};

struct						s_map
{
	int						x;
	int						y;
	int						y_max;
	int						x_max;
	char					*file_name;
	char					*line;
	int						fd_map;
	char					**map;
	char					*n_wall_path;
	char					*s_wall_path;
	char					*e_wall_path;
	char					*w_wall_path;
	char					*floor_color;
	char					*ceiling_color;
};

struct						s_key
{
	bool					w_key;
	bool					a_key;
	bool					s_key;
	bool					d_key;
	bool					f_key;
	bool					left_key;
	bool					right_key;
	bool					tab_key;
	bool					shift_l_key;
};

struct						s_data
{
	t_map					*map;
	t_mlx					*mlx;
	t_texture				*texture;
	t_player				*player;
	t_ray					*ray;
	t_img					*img;
	t_key					*key;
	void					*win;
};

struct						s_mlx
{
	void					*mlx;
};

double						get_time_to_msec(void);
void						my_mlx_put_pixel(t_img *img, int x, int y,
								int color);
void						print_texture(t_data *data, int i, int j);
void						my_mlx_put_pixel(t_img *img, int x, int y,
								int color);
void						norm_angle(double *angle);
int							ray_dir(double angle, int mode);
bool						is_wall(t_map *map, double x, double y);
int							balance_inter(double angle, double *inter,
								double *step, int mode);
void						raycast_loop(t_data *data);
double						lazerizor(t_data *data, double angle);
int							close_window(t_data *data);
int							handle_press_key(int keycode, t_data *data);
int							handle_release_key(int keycode, t_data *data);
int							move_player(t_data *data);
void						free_all(t_data *data);
void						print_error_asset(t_data *data);
void						print_map_and_params(t_data *data);
void						draw_fps(t_data *data, double current_time_ms);

#endif
