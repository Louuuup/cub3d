/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:14:58 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/12/13 14:39:19 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void move_player(t_data *data, double angle_offset)
{
	double angle;
	
	angle = data->player.angle + angle_offset;
	if (can_move(data, angle) == TRUE)
	{
		data->player.co.x += cos(angle) * SPEED;
		data->player.co.y += sin(angle) * SPEED;
		reload();
		printf("Moving: "RED"[%.1f;%.1f]"RESET"->"RED"[%.1f;%.1f]\n"RESET"", \
		data->player.co.y - sin(angle) * SPEED, data->player.co.x - cos(angle) \
		* SPEED, data->player.co.y, data->player.co.x);
	}
	else
		printf("Can't move!\n");
}
void	mv_right()
{
	t_data *data;
	
	data = get_data();
	move_player(data, -M_PI_2);

}

void	mv_left()
{
	t_data *data;

	data = get_data();
	move_player(data, M_PI_2);
}

void	mv_up()
{
	t_data *data;
	
	data = get_data();
	move_player(data, 0);
}

void	mv_down()
{
	t_data *data;

	data = get_data();
	move_player(data, M_PI);
}
