#include "mlx_management.h"
#include "parsing.h"

void	get_angle(t_data *data, char c, int y, int x)
{
	if (c == 'N')
		data->player->angle = 3 * M_PI_2;
	else if (c == 'S')
		data->player->angle = M_PI_2;
	else if (c == 'W')
		data->player->angle = M_PI;
	else
		data->player->angle = 0;
	data->player->px = (float)x * TILE + TILE / 2;
	data->player->py = (float)y * TILE + TILE / 2;
}

static int	check_char(t_data *data, char **map, int *y, int *x)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (char_compare(map[*y][*x]) == 1)
				return (1);
			if (map[*y][*x] == 'N' || map[*y][*x] == 'S' || map[*y][*x] == 'W'
				|| map[*y][*x] == 'E')
				get_angle(data, map[*y][*x], *y, *x);
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}

int	check_map_validity(t_data *data, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (check_char(data, map, &y, &x) == 1)
	{
		ft_putstr_fd("Error: wrong char in map x = ", 2);
		ft_putnbr_fd(x, 2);
		ft_putstr_fd(" y = ", 2);
		ft_putnbr_fd(y, 2);
		ft_putstr_fd(" char = ", 2);
		ft_putchar_fd(map[y][x], 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}
