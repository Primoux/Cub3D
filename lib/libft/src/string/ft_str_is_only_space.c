#include "libft.h"

int	ft_str_is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_is_white_space(str[i]))
			i++;
		else
			return (1);
	}
	return (0);
}
