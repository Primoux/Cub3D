#include "cub3d.h"
#include "mlx_management.h"

void	winner(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "prout");
    data->img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
            &data->img->line_length, &data->img->endian);
    mlx_hook(data->win, 2, 1L << 0, handle_key, data); //press
    mlx_hook(data->win, 3, 1L << 1, handle_key, data); //release
    imaginer(data);
    raycaster(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
    mlx_hook(data->win, 17, 0, close_window, data);
    // mlx_loop_hook(mlx, &hooks, &data);
    mlx_loop(data->mlx);

    // hook key_pressed -> code si code == XK_a -> bool  de direction left = true; 
    // hook key_realease -> code si code == XK_a -> bool  de direction left = false; 

}
