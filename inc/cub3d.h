#ifndef CUB3D_H
# define CUB3D_H

// Dell
// # define HEIGHT 1080
// # define WEIGHT 720

// Pas dell
# define HEIGHT 75*5
# define WEIGHT 75*5

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

struct					s_img
{
	void				*floor;
	void				*wall;
};

struct					s_map
{
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
	void				*win;
};

struct					s_mlx
{
	void				*mlx;
	void				*mlx_win;
};

int						close_window(t_data *data);
int						handle_key(int keycode, t_data *data);
int						init(t_data *data);
void					free_all(t_data *data);
void					print_error_asset(t_data *data);
void					print_map(t_data *data);

#endif
