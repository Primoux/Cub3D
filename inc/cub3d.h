#ifndef CUB3D_H
# define CUB3D_H

# define FOV 90

// Dell
# define HEIGHT 1080
# define WIDTH 1920
// Mac
// # define HEIGHT 2160
// # define WIDTH 3840

//# define M_PI 3.14159265359
//# define M_PI2 1.57079632679
//# define M_2PI 6.28318530718

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img	t_img;
typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;
typedef struct s_map	t_map;
typedef struct s_player	t_player;
typedef struct s_ray	t_ray;

struct					s_img
{
	void				*floor;
	void				*wall;
	void				*perso_n;
};

struct					s_player
{
	double				px;
	double				py;
	float				rad;
	double				angle;
};

struct					s_ray
{
	double				rx;
	double				ry;
	float				rad_fov;
	double				angle;
};

struct					s_map
{
	int					x;
	int					y;
	int					y_max;
	int					x_max;
	char				*file_name;
	char				*line;
	int					fd_map;
	char				**map;
	char				*n_wall_path;
	char				*s_wall_path;
	char				*e_wall_path;
	char				*w_wall_path;
	char				*floor_color;
	char				*sky_color;
};

struct					s_data
{
	t_map				*map;
	t_mlx				*mlx;
	t_img				*img;
	t_player			*player;
	t_ray				*ray;
	void				*win;
};

struct					s_mlx
{
	void				*mlx;
	void				*mlx_win;
};

void					norm_angle(double *angle);
int						ray_dir(double angle, int mode);
bool					is_wall(t_map *map, double x, double y);
int						balance_inter(double angle, double *inter, double *step,
							int mode);
void					raycaster(t_data *data);
void					lazerizor(t_data *data, double angle);
int						close_window(t_data *data);
int						handle_key(int keycode, t_data *data);
int						init(t_data *data);
void					free_all(t_data *data);
void					print_error_asset(t_data *data);
void					print_map_and_params(t_data *data);

#endif
