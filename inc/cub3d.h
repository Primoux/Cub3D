#ifndef CUB3D_H
# define CUB3D_H


//Dell
# define HEIGHT 1080
# define WEIGHT 1920

#include "libft.h"
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include <X11/keysym.h>

typedef  struct s_img	t_img;
typedef struct s_mlx	t_mlx;
typedef struct s_data	t_data;

struct s_data
{
	char	**map;
	t_mlx	*mlx;
	t_img	*img;
	void	*win;
};

struct s_img
{
	void			*floor;
	void			*wall;
};

struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
};

void	init(t_data *data);
int		close_window(t_data *data);
int		handle_key(int keycode, t_data *data);

#endif
