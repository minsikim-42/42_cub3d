#include "cub3d.h"

int		go_stopping(t_map map, t_player player)
{
	double	v_x;
	double	v_y;

	v_x = player.vec_x;
	v_y = player.vec_y;
	if (player.vec_y < 0.3 && player.vec_y > 0)
		v_y = 0.3;
	if (player.vec_y > -0.3 && player.vec_y < 0)
		v_y = -0.3;
	if (player.vec_x < 0.3 && player.vec_x > 0)
		v_x = 0.3;
	if (player.vec_x > -0.3 && player.vec_x < 0)
		v_x = -0.3;
	if (map.maparr [(int)(player.y + v_y * 3 * player.move_speed) / BITSIZE]\
		[(int)(player.x + v_x * 3 * player.move_speed) / BITSIZE] == '1')
		return (0);
	return (1);
}

int		back_stopping(t_map map, t_player player)
{
	double	v_x;
	double	v_y;

	v_x = player.vec_x;
	v_y = player.vec_y;
	if (player.vec_y < 0.3 && player.vec_y > 0)
		v_y = 0.3;
	if (player.vec_y > -0.3 && player.vec_y < 0)
		v_y = -0.3;
	if (player.vec_x < 0.3 && player.vec_x > 0)
		v_x = 0.3;
	if (player.vec_x > -0.3 && player.vec_x < 0)
		v_x = -0.3;
	if (map.maparr [(int)(player.y - v_y * player.move_speed) / BITSIZE]\
		[(int)(player.x - 3 * v_x * player.move_speed) / BITSIZE] == '1')
		return (0);
	return (1);
}

void	moving(t_data *data, t_player *player)
{
	int x = player->x;
	int y = player->y;

	remove_pix(data, player);
	if (player->up || player->down || player->left || player->right)
	{
		for(int i = (-1) * data->map.width / 2; i < data->map.width / 2; i++)
		{
			remove_find_wall(data, data->player, data->player.theta + ((double)i / (data->map.width / 2)) * (M_PI / 6), i);
		}
	}
	player->vec_x = cos(player->theta);
	player->vec_y = sin(player->theta);

	if (player->left == 1)
		player->theta -= data->rotate_speed;
	if (player->right == 1)
		player->theta += data->rotate_speed;
	if (player->up == 1 && go_stopping(data->map, *player))
	{
		remove_pix(data, player);
		player->x += player->vec_x * player->move_speed;
		player->y += player->vec_y * player->move_speed;
	}
	if (player->down == 1 && back_stopping(data->map, *player))
	{
		remove_pix(data, player);
		player->x -= player->vec_x * player->move_speed;
		player->y -= player->vec_y * player->move_speed;
	}
}
