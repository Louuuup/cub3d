/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:14:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/05 12:44:19 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mv_right()
{
	t_data *data;
	
	data = get_data();
	if (data->map->map[(int)data->player.co.y][(int)(data->player.co.x + SPEED)] != '1')
	{
		data->player.co.x += SPEED;
		reload();
		printf("Moving right\n");
	}
	else 
		printf("Can't move right\n");
}

void	mv_left()
{
	if (get_data()->map->map[(int)get_data()->player.co.y][(int)(get_data()->player.co.x - SPEED)] != '1')
	{
		get_data()->player.co.x -= SPEED;
		reload();
		printf("Moving left\n");
	}
	else 
		printf("Can't move left\n");
}

void	mv_up()
{
	t_data *data;
	
	data = get_data();
	if (data->map->map[(int)(data->player.co.y - SPEED)][(int)data->player.co.x] != '1')
	{
		data->player.co.y -= SPEED;
		reload();
		printf("Moving up\n");
	}
	else 
		printf("Can't move up\n");

	printf("Moving up\n");
}

void	mv_down()
{
	t_data *data;

	data = get_data();
	
	if (data->map->map[(int)(data->player.co.y + SPEED)][(int)data->player.co.x] != '1')
	{
		data->player.co.y += SPEED;
		reload();
		printf("Moving down\n");
	}
	else 
		printf("Can't move down\n");
}

