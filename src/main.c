#include "mlx_management.h"
#include "parsing.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_dprintf(2, "Usage: ./cub3d <map.cub>\n");
		return (2);
	}
	if (init(&data) == 1 || parsing(&data, argv[1]) == 1)
	{
		free_all(&data);
		return (1);
	}
	winner(&data);
	free_all(&data);
}
