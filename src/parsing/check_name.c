#include "parsing.h"

int	check_name(char *argv)
{
	size_t	length;

	if (!argv)
		return (1);
	length = ft_strlen(argv);
	if (length < 4)
	{
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	if (ft_strncmp(&argv[length - 4], ".cub", 4) != 0)
	{
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	return (0);
}
