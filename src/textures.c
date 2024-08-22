/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:45:56 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/22 15:13:02 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void texture_handler()
{
	t_data *data;

	data = get_data();
	if (debug())
		printf("Loading textures...\n");
	printf("here\n");
	data->map->player->texture = texture_inject(data->map->player->texture, "textures/mini_player.png");
	data->map->player->image = texture_load(data->mlx, data->map->player->texture);
	data->map->wall->texture = texture_inject(data->map->wall->texture, "textures/mini_wall.png");
	data->map->wall->image = texture_load(data->mlx, data->map->wall->texture);
	data->map->hud->texture = texture_inject(data->map->hud->texture, "textures/hud.png");
	data->map->hud->image = texture_load(data->mlx, data->map->hud->texture);
	if (debug())
		printf("Textures loaded\n");
}
