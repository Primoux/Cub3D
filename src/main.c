#include "mlx_management.h"
#include "parsing.h"

int	check_format(char *map, t_color *color)
{
	int		error;
	char	*str;

	error = 0;
	color->red = ft_atoi(map, &error);
	str = ft_strchr(map, ',');
	color->green = ft_atoi(++str, &error);
	str = ft_strchr(str, ',');
	color->blue = ft_atoi(++str, &error);
	if (error != 0)
		return (1);
	return (0);
}

int	set_color(t_data *data)
{
	if (check_format(data->map->ceiling_color, &data->texture->ceiling) == 1)
		return (1);
	if (check_format(data->map->floor_color, &data->texture->floor) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: ./cub3d <map.cub>\n");
		return (2);
	}
	if (init(&data) == 1 || parsing(&data, argv[1]) == 1 || set_color(&data))
	{
		free_all(&data);
		return (1);
	}
	winner(&data);
	free_all(&data);
}
