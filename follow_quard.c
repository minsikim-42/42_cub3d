#include "cub3d.h"

double	follow_x1(t_data *data, t_player player, double theta)
{
	int		w_x;
	int		w_y;
	double	d_x;
	double	d_y;

	data->short_x = 0;
	w_x = (int)(player.x) / BITSIZE * BITSIZE + BITSIZE;
	w_y = (int)(player.y) / BITSIZE * BITSIZE + BITSIZE;
	while (data->map.maparr[w_y / BITSIZE - 1][w_x / BITSIZE - 1] != '1')
	{
		d_x = (w_x - player.x) / cos(theta);
		d_y = (w_y - player.y) / sin(theta);
		if (d_x < 0)
			d_x *= -1;
		if (d_y < 0)
			d_y *= -1;

		if (d_x < d_y)
			w_x += BITSIZE;
		else
			w_y += BITSIZE;
	}

	data->wall_x = w_x;
	data->wall_y = w_y;
	if (d_x < d_y)
	{
		data->short_x = 1;
		return (d_x);
	}
	else
		return (d_y);
}

double	follow_x2(t_data *data, t_player player, double theta)
{
	int		w_x;
	int		w_y;
	double	d_x;
	double	d_y;

	data->short_x = 0;
	w_x = (int)(player.x) / BITSIZE * BITSIZE;
	w_y = (int)(player.y) / BITSIZE * BITSIZE + BITSIZE;
	while (data->map.maparr[w_y / BITSIZE - 1][w_x / BITSIZE] != '1')
	{
		d_x = (w_x - player.x) / cos(theta);
		d_y = (w_y - player.y) / sin(theta);
		if (d_x < 0)
			d_x *= -1;
		if (d_y < 0)
			d_y *= -1;

		if (d_x < d_y)
			w_x -= BITSIZE;
		else
			w_y += BITSIZE;
	}
	data->wall_x = w_x;
	data->wall_y = w_y;
	if (d_x < d_y)
	{
		data->short_x = 1;
		return (d_x);
	}
	else
		return (d_y);
}

double	follow_x3(t_data *data, t_player player, double theta)
{
	int		w_x;
	int		w_y;
	double	d_x;
	double	d_y;

	data->short_x = 0;
	w_x = (int)(player.x) / BITSIZE * BITSIZE;
	w_y = (int)(player.y) / BITSIZE * BITSIZE;
	while (data->map.maparr[w_y / BITSIZE][w_x / BITSIZE] != '1')
	{
		d_x = (w_x - player.x) / cos(theta);
		d_y = (w_y - player.y) / sin(theta);
		if (d_x < 0)
			d_x *= -1;
		if (d_y < 0)
			d_y *= -1;

		if (d_x < d_y)
			w_x -= BITSIZE;
		else
			w_y -= BITSIZE;
	}
	data->wall_x = w_x;
	data->wall_y = w_y;
	if (d_x < d_y)
	{
		data->short_x = 1;
		return (d_x);
	}
	else
		return (d_y);
}

double	follow_x4(t_data *data, t_player player, double theta)
{
	int		w_x;
	int		w_y;
	double	d_x;
	double	d_y;

	data->short_x = 0;
	w_x = (int)(player.x) / BITSIZE * BITSIZE + BITSIZE;
	w_y = (int)(player.y) / BITSIZE * BITSIZE;
	while (data->map.maparr[w_y / BITSIZE][w_x / BITSIZE - 1] != '1')
	{
		d_x = (w_x - player.x) / cos(theta);
		d_y = (w_y - player.y) / sin(theta);
		if (d_x < 0)
			d_x *= -1;
		if (d_y < 0)
			d_y *= -1;

		if (d_x < d_y)
			w_x += BITSIZE;
		else
			w_y -= BITSIZE;
	}
	data->wall_x = w_x;
	data->wall_y = w_y;
	if (d_x < d_y)
	{
		data->short_x = 1;
		return (d_x);
	}
	else
		return (d_y);
}