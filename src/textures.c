/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:45:56 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/07 19:58:40 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Only called on launch, creates textures with inject function
static void texture_create(t_data *data)
{
	if (debug())
		printf("Creating textures...\n");
	data->a2d.player->texture = texture_inject(data->a2d.player->texture, "textures//mini/mini_player.png");
	data->a2d.wall->texture = texture_inject(data->a2d.wall->texture, "textures/mini/mini_wall.png");
	data->a2d.hud->texture = texture_inject(data->a2d.hud->texture, "textures/hud.png");
	// data->map->mouse->texture = texture_inject(data->map->mouse->texture, "textures/invisible_cursor.png");
	// data->map->cursor = mlx_create_cursor(data->map->player->texture);
	// 
	if (debug())
		printf("Textures created\n");
}
//Called on each reload and on launch, loads textures
void texture_load_all(t_data *data)
{
	if (debug())
		printf("Loading textures...\n");
	if (!data->a2d.player->image)
		data->a2d.player->image = texture_load(data->mlx, data->a2d.player->texture);
	if (!data->a2d.wall->image)
		data->a2d.wall->image = texture_load(data->mlx, data->a2d.wall->texture);	
	if (!data->a2d.hud->image)
		data->a2d.hud->image = texture_load(data->mlx, data->a2d.hud->texture);
	if (debug())
		printf("Textures loaded\n");
}
//Called on first launch, creates and loads all textures
void texture_handler(void)
{
	t_data *data;

	data = get_data();

	texture_create(data);
	texture_load_all(data);


}
