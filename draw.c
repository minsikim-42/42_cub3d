#include "cub3d.h"

void	remove_pix(t_data *data, t_player *player)
{
	int		x = player->x;
	int		y = player->y;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			my_mlx_pixel_put(data, x + player->vec_x * (data->aim + 19) + i - 3, y + player->vec_y * (data->aim + 19) + j - 3, 0x00000000);
		}
	}
	for(int i = -20 / 2; i < 20 / 2; i++)
	{
		for(int j = -20 / 2; j < 20 / 2; j++)
		{
			my_mlx_pixel_put(data, x + i, y + j, 0);
		}
	}
}

void	draw_up_down(t_data *data, t_map map)
{
	int		i;
	int		j;
	int		color;

	i = -1;
	while (++i < map.width)
	{
		j = -1;
		while(++j < map.height / 2)
		{
			my_mlx_pixel_put(data, i, map.height / 2 + j, map.info.f); //set_color(800 - j)); //
			my_mlx_pixel_put(data, i, map.height / 2 - j, map.info.c); //set_color(800 - j)); //
		}
	}
}

void	draw(t_data *data, t_player *player, int color)
{
	// draw_aim(*data, *player);
	// draw_hack(data, player, 18, 0x0064D897);
	draw_up_down(data, data->map);
}