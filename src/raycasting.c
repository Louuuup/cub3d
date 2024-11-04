/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:17 by adube             #+#    #+#             */
/*   Updated: 2024/11/04 11:59:03 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the idea is to check at every side of a wall the ray will encounter. We give each\
square width 1, so each side of a wall is an integer value and the places in between\
have a value after the point. Now the step size isn't constant, it depends on the\
distance to the next side. 

// USE DDA: Digital Differential Analysis

//note to fix fisheye effect: correct the distance by reducing it according to\
the given ray's angle delta. Rays that go away from the camera center will result\
in a bigger distance so you will need the delta (i.e. the angle difference between\
the most central ray (FOV/2) and the given ray that you're trying to perform correction to).

#include "cub3d.h"

int	unit_circle(float angle, char c)	// check the unit circle
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

float get_angle_dir(float angle)
{
	if (angle < 0)
		angle += (2 * M_PI);
	if (angle > (2 * M_PI))
		angle -= (2 * M_PI);
	return (angle);
}

int wall_hit(float x, float y, t_player *player)
{
	int  map_x; //replace by the one in the struct
	int  map_y; //replace by the one in the struct
	float	SIZE = 20; //CHANGE TO ONE IN .H WHERE TILE HAS 64px IN SIZE

	if (x < 0 || y < 0)
		return (0);
	map_x = floor (x / SIZE);
	map_y = floor (y / SIZE);
	if ((map_y >= HEIGHT || map_x >= WIDTH))
		return (0);
	if (map_array[map_y] && map_x <= (int)strlen(map_array[map_y]))
		if (map_array[map_y][map_x] == '1')
			return (0);
	return (1);
}

int get_border(float angle, float *border, float *add, int is_horizon)
{
	float	SIZE = 20; //CHANGE TO ONE IN .H WHERE TILE HAS 64px IN SIZE
	
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*border += SIZE;
			return (-1);
		}
		*add *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2)) 
		{
			*border += SIZE;
			return (-1);
		}
		*add *= -1;
	}
	return (1);
}

float get_y_border(t_player *player, float angle)
{
	float	x;
	float	y;
	int		pixel;
	float	x_add;
	float	y_add;
	float	SIZE = 20; //add to .h, to have a fixed size for our tiles

	y_add = SIZE;
	x_add = SIZE * tan(angle);
	y = floor(player->y / SIZE) * SIZE;
	pixel = get_border(angle, &y, &y_add, 1);
	x = player->x + (y - player->y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_add > 0) || (!unit_circle(angle, 'y') && x_add < 0))
		x_add *= -1;
	while (wall_hit(x, y - pixel, player))
	{
		x += x_add;
		y += y_add;
	}
	return (sqrt(pow(x - player->x, 2) + pow(y - player->y, 2)));
}

float	get_x_border(t_player *player, float angle)
{
	float	x;
	float	y;
	int		pixel;
	float	x_add;
	float	y_add;
	float	SIZE = 20; //add to .h, to have a fixed size for our tiles

	x_add = SIZE;
	y_add = SIZE * tan(angle);
	x = floor(player->x / SIZE) * SIZE;
	pixel = get_border(angle, &x, &x_add, 0);
	y = player->y + (x - player->x) * tan(angle);
	if ((unit_circle(angle, 'x') && y_add < 0) || (!unit_circle(angle, 'x') && y_add > 0))
		y_add *= -1;
	while (wall_hit(x - pixel, y, player))
	{
		x += x_add;
		y += y_add;
	}
	return (sqrt(pow(x - player->x, 2) + pow(y - player->y, 2)));
}

void	raycasting()
{
	int ray = 0;
	ray_angle = player->angle - (player->fov / 2)
	while (ray < WIDTH)
	{
		//have flag for wall hitting
		double ray_dir_x = get_x_border(playerstruct, get_angle_dir(ray_angle));
		double ray_dir_y = get_y_border(player_struct, get_angle_dir(ray_angle));
		if (ray_dir_x <= ray_dir_y)
			mlx->ray->distance = ray_dir_y;
		else
		{
			mlx->ray->distance = ray_dir_x;
			//flag for hit wall
		}
		draw_wall();
		ray++;
		ray_angle += (player->fov / WIDTH);
	}
}