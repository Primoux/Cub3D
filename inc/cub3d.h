#ifndef CUB3D_H
# define CUB3D_H

# define FOV 70

// Dell
# define HEIGHT 1080
# define WIDTH 1920
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
	void					*wall;
	void					*perso_n;
};

struct						s_player
{
	double					px;
	double					py;
	float					rad;
	double					angle;
};

struct						s_ray
{
	double				rx;
	double				ry;
	float				rad_fov;
	double				angle;
	double				ray_dist;
	double				rx_dist;
	double				ry_dist;

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

void						my_mlx_put_pixel(t_img *img, int x, int y,
								int color);
void						norm_angle(double *angle);
int							ray_dir(double angle, int mode);
bool						is_wall(t_map *map, double x, double y);
int							balance_inter(double angle, double *inter,
								double *step, int mode);
void						raycaster(t_data *data);
double						lazerizor(t_data *data, double angle);
int							close_window(t_data *data);
int							handle_press_key(int keycode, t_data *data);
int							handle_release_key(int keycode, t_data *data);
int							move_player(t_data *data);
int							init(t_data *data);
void						free_all(t_data *data);
void						print_error_asset(t_data *data);
void						print_map_and_params(t_data *data);

#endif
