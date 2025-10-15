#include "cub3d.h"

int	init(t_data *data)
{
	if (init_base(data) != 0)
		return (1);
	if (init_map(data) != 0)
		return (1);
	if (init_texture(data) != 0)
		return (1);
	if (init_ray(data) != 0)
		return (1);
	if (init_img(data) != 0)
		return (1);
	if (init_keys(data) != 0)
		return (1);
	return (0);
}
