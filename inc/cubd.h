#ifndef CUB3D_H
# define CUB3D_H

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	struct t_mlx *mlx;
} t_data;

typedef struct s_mlx
{
	void *mlx;
	void *mlx_win;
} t_mlx;


#endif
