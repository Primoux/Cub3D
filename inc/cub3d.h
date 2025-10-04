#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char			**map;
	struct t_mlx	*mlx;
	struct t_img	*img;
}					t_data;

typedef struct s_img
{
	void			*floor;
	void			*wall;
}					t_img;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
}					t_mlx;

#endif
