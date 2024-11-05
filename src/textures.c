/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:45:56 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/05 11:55:42 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void texture_handler()
{
	t_data *data;

	data = get_data();
	if (debug())
		printf("Loading textures...\n");
	data->map->player->texture = texture_inject(data->map->player->texture, "textures/mini_player.png");
	if (!data->map->player->image)
		data->map->player->image = texture_load(data->mlx, data->map->player->texture);
	data->map->wall->texture = texture_inject(data->map->wall->texture, "textures/mini_wall.png");
	if (!data->map->wall->image)
		data->map->wall->image = texture_load(data->mlx, data->map->wall->texture);	
	data->map->hud->texture = texture_inject(data->map->hud->texture, "textures/hud.png");
	if (!data->map->hud->image)
		data->map->hud->image = texture_load(data->mlx, data->map->hud->texture);
	if (debug())
		printf("Textures loaded\n");
}
