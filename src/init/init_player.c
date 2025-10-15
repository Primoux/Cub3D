#include "cub3d.h"

int	init_player(t_player *player)
{
	if (!player)
		return (1);
	player->px = 0;
	player->py = 0;
	player->angle = 0;
	return (0);
}
