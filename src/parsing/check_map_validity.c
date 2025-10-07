#include "parsing.h"

void	get_angle(t_data *data, char c)
{
	if (c == 'N')
	{
	}
	else if (c == 'S')
	{
	}
	else if (c == 'W')
	{
	}
	else
	{
	}
	(void)data;
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
				get_angle(data, map[*y][*x]);
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
