#include "cub3d.h"

void	remove_pix(t_data *data, t_player *player)
{
	int		x;
	int		y;

	x = player->x;
	y = player->y;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			my_mlx_pixel_put(data, x + player->vec_x * (data->aim + 19) + i - 3,\
							y + player->vec_y * (data->aim + 19) + j - 3, 0x00000000);
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

void	draw_aim(t_data data, t_player player)
{
	float x = player.x;
	float y = player.y;

	for (int i = 0; i < 4; i++) // aim
	{
		for (int j = 0; j < 4; j++)
		{
			my_mlx_pixel_put(&data, x + player.vec_x * (data.aim + 19) + i - 2, y + player.vec_y * (data.aim + 19) + j - 2, 0x00FF0000);
		}
	}
}

void	draw_hack(t_data *data, t_player *player, int ga, int color)
{
	int		x = player->x;
	int		y = player->y;

	for(int i = -ga / 2; i < ga / 2; i++)
	{
		for(int j = -ga / 2; j < ga / 2; j++)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
		}
	}
}

void	vec_mlx_pixel_put(t_data *data, t_player *player, int i, int j, int color)
{
	char	*dst;
	float	x = player->x;
	float	y = player->y;

	dst = (char *)data->addr + ((int)(y + i * player->vec_y \
										+ j * sin(player->theta + M_PI_2)) * data->line_length
										+ (int)(x + i * player->vec_x \
										+ j * cos(player->theta + M_PI_2)) * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
