#include "parsing.h"
#include <fcntl.h>

int	check_name_and_access(t_data *data, char *argv)
{
	size_t	length;

	if (!argv)
		return (1);
	length = ft_strlen(argv);
	if (length < 4 || ft_strncmp(&argv[length - 4], ".cub", 4) != 0)
	{
		ft_dprintf(2, "Error: argument must have a '.cub' extension\n");
		return (1);
	}
	data->map->fd_map = open(argv, O_RDONLY);
	if (data->map->fd_map == -1)
	{
		perror(argv);
		return (1);
	}
	return (0);
}
