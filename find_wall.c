#include "cub3d.h"

int		check_quard(double theta)
{
	double	vec_x;
	double	vec_y;

	vec_y = sin(theta);
	vec_x = cos(theta);
	if (vec_x >= 0)
	{
		if (vec_y >= 0)
			return (1);
		else if (vec_y < 0)
			return (4);
	}
	else
	{
		if (vec_y >= 0)
			return (2);
		if (vec_y < 0)
			return (3);
	}
	return (0);
}

void	remove_find_wall(t_data *data, t_player player, double theta, int i)
{
	int		quard;
	int		w_x;
	int		w_y;
	double	short_d;

	quard = check_quard(theta);
	if (quard == 1)
	{
		short_d = follow_x1(data, player, theta);
		remove_pixel_put_wall(data, (int)short_d, i);
	}
	if (quard == 2)
	{
		short_d = follow_x2(data, player, theta);
		remove_pixel_put_wall(data, (int)short_d, i);
	}
	if (quard == 3)
	{
		short_d = follow_x3(data, player, theta);
		remove_pixel_put_wall(data, (int)short_d, i);
	}
	if (quard == 4)
	{
		short_d = follow_x4(data, player, theta);
		remove_pixel_put_wall(data, (int)short_d, i);
	}
}

void	find_wall(t_data *data, t_player player, double theta, int i)
{
	int		quard;
	int		w_x;
	int		w_y;
	double	short_d;

	quard = check_quard(theta);
	if (quard == 1)
	{
		short_d = follow_x1(data, player, theta);
		if (data->short_x == 1)
			pixel_put_wall_1(data, short_d, theta, i);
		else
			pixel_put_wall_2(data, short_d, theta, i);
	}
	if (quard == 2)
	{
		short_d = follow_x2(data, player, theta);
		
		if (data->short_x == 1)
			pixel_put_wall_1(data, short_d, theta, i);
		else
			pixel_put_wall_2(data, short_d, theta, i);
	}
	if (quard == 3)
	{
		short_d = follow_x3(data, player, theta);
		if (data->short_x == 1)
			pixel_put_wall_1(data, short_d, theta, i);
		else
			pixel_put_wall_2(data, short_d, theta, i);
	}
	if (quard == 4)
	{
		short_d = follow_x4(data, player, theta);
		if (data->short_x == 1)
			pixel_put_wall_1(data, short_d, theta, i);
		else
			pixel_put_wall_2(data, short_d, theta, i);
	}
}
