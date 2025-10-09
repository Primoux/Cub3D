
double	y_inter(t_data *data, double angle)
{
	double x;
	double y;
	double x_step;
	double y_step;
	int pixel;

	x_step = TILE;
	y_step = TILE * tan(angle);
	x = floor(data->player->px / TILE) * TILE;
	pixel = balance_inter(angle, &x, &x_step); //corriger angle x et x_step
	y = data->player->py + (x - data->player->px) * tan(angle);
	if ((ray_dir(angle) && y_step < 0 )||(!ray_dir(angle) && y_step > 0)) //rediriger lazer de y_step du bon cote en fontion de l'angle (droite ou gauche du cercle trigo)
		y_step *= -1;
	check_rad(data, angle, &x_step, &y_step);
	while (!is_wall(data->map, x + pixel, y))
	{
		printf("(fonction y_inter) [x] = %f [%d] | [y] = %f [%d]\n", x, (int)x , y, (int)y);
//		printf("(fonction y_inter) [xstep] = %f [%d] | [ystep] = %f [%d]\n", x_step, (int)x, y_step, (int)y);
		mlx_pixel_put(data->mlx, data->win, (int)x  , (int)y, 0x00FF0000);
		y += y_step;
		x += x_step;
		usleep(500);
	}
	data->ray->rx = x;
	data->ray->ry = y;
	return (sqrt(pow(data->player->py - y, 2) + pow(data->player->px - x, 2)));
}