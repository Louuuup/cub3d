/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:43:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/22 15:12:45 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_data *data, mlx_t *mlx, t_map *map)
{
	mlx_image_to_window(mlx, map->hud->image, 0, 0);
	mlx_image_to_window(mlx, map->wall->image, map->start.x, map->start.y);
	(void)data;
}


void	minimap_player(void)
{
	t_data *data;

	data = get_data();
}