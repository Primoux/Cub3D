/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 21:54:50 by enchevri          #+#    #+#             */
/*   Updated: 2025/10/30 16:01:30 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdint.h>

typedef struct s_texture	t_texture;
typedef struct s_mlx		t_mlx;
typedef struct s_data		t_data;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_ray		t_ray;
typedef struct s_key		t_key;
typedef struct s_destroy	t_destroy;

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
	double					x;
	double					y;
	float					rad;
	double					angle;
	double					last_frame_time;
	unsigned int			blocks;
};

struct						s_ray
{
	double					rx;
	double					ry;
	double					ratio;
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
	int						check_x;
	int						check_y;
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
	bool					mouse_1;
	bool					mouse_3;
	bool					w_key;
	bool					a_key;
	bool					s_key;
	bool					d_key;
	bool					f_key;
	bool					f3_key;
	bool					left_key;
	bool					right_key;
	bool					tab_key;
	bool					shift_l_key;
};

struct						s_destroy
{
	double					begin_destroy;
	int						x;
	int						y;
	char					saved_block;
	int						stage;
	bool					destroying;
	bool					pointer_hit;
	int						pt_x;
	int						pt_y;
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
	t_destroy				*destroy;
	void					*win;
};

struct						s_mlx
{
	void					*mlx;
};

#endif
