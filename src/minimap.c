/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:43:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/12/13 15:29:13 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void mini_draw(char c, t_co co)
{
	if (c == '0')
	{
		print_co(co, "Floor", PURPLE);

	}
	else if (c == '1')
	{
		print_co(co, "Wall", PURPLE);
		put_on_screen(get_data()->a2d.wall->image, co.x, co.y, "WALL");
	}
	// else
	// {
	// 	if (debug())
	// 	{
	// 		printf("Error: %c\n", c);
	// 		t_co tmp;
	// 		tmp.x = co.x;
	// 		tmp.y = co.y;
	// 		print_co(tmp, "COULDNT PRINT", CYAN);
	// 	}
	// }

}

void load_minimap(t_data *data, mlx_t *mlx, t_map *map)
{
	t_co map_co;
	t_co px_co;
	
	(void)mlx;
	(void)data;
	px_co = map->start;
	map_co.y = data->player.co.y - 15;

	if (debug())
		printf("Drawing minimap\n");
	while (map_co.y < data->player.co.y + 15)
	{
		map_co.x = data->player.co.x - 15;
		px_co.x = map->start.x;
		while (map_co.x < data->player.co.x + 15)
		{
			if (map_co.x >= 0 && map_co.y >= 0)
			{
				mini_draw(map->map[(int)map_co.y][(int)map_co.x], px_co);
			}
			px_co.x += MINI_SCALE;
			map_co.x++;
		}
		px_co.y += MINI_SCALE;
		map_co.y++;
	}
		
}


void	draw_minimap(t_data *data, mlx_t *mlx, t_map *map)
{

	put_on_screen(data->a2d.player->image, data->player.m_co.x, data->player.m_co.y, "PLAYER");
	put_on_screen(data->a2d.hud->image, 0, 0, "HUD");
	// put_on_screen(map->player->image, map->start.x, map->start.y, "MAP CORNER A");
	// put_on_screen(map->wall->image, 1765, 145, "middle");
	// put_on_screen(map->player->image, map->end.x, map->end.y, "MAP CORNER B");

	load_minimap(data, mlx, map);
}
