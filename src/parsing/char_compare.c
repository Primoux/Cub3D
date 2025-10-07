#include "parsing.h"

int	char_compare(char c)
{
	size_t i;

	i = 0;
	while (VALID_CHARS[i])
	{
		if (VALID_CHARS[i] == c)
			return (0);
		i++;
	}
	return (1);
}
