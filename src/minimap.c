/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:43:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/04 11:02:49 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void mini_draw(char c, int x, int y)
{
	if (c == '0')
	{
		if (debug())
			printf("printing floor(nothing)\n");
	}
	else if (c == '1')
		put_on_screen(get_data()->map->wall->image, x, y, "WALL");
	else
	{
		if (debug())
		{
			t_co tmp;
			tmp.x = x;
			tmp.y = y;
			print_co(tmp, "COULDNT PRINT", CYAN);
		}
	}

}

static void mini_draw_loop(t_data *data, mlx_t *mlx, t_map *map)
{
	t_co co;
	t_co max;

	co.y = data->player.co.y - 9.5;
	max.y = co.y + 20;
	data->scr_co.y = map->start.y /*+ (data->player.co.y)*/;
	print_co(data->scr_co, "minimap start", CYAN);
	print_co(co, "Grid start", PURPLE);
	print_co(max, "Max grid", PURPLE);
	print_map(map);
	while (co.y < max.y)
	{
		co.x = data->player.co.x - 9.5;
		data->scr_co.x = map->start.x /*+ (data->player.co.x)*/;
		while (co.x < max.x)
		{
			print_co(co, "working on...``", PURPLE);
			if (co.x >= 0 && co.y >= 0 && co.x < map->width && co.y < map->height)
				mini_draw(map->map[(int)co.y][(int)co.x], data->scr_co.x, data->scr_co.y);
			co.x++;
			data->scr_co.x += MINI_SCALE;
		}
		co.y++;
		data->scr_co.y += MINI_SCALE;
	}

}

void	draw_minimap(t_data *data, mlx_t *mlx, t_map *map)
{

	put_on_screen(map->hud->image, 0, 0, "HUD");
	
	put_on_screen(map->player->image, data->player.m_co.x, data->player.m_co.y, "PLAYER");

	put_on_screen(map->player->image, map->start.x, map->start.y, "MAP CORNER A");
	put_on_screen(map->wall->image, 1765, 145, "middle");
	put_on_screen(map->player->image, map->end.x, map->end.y, "MAP CORNER B");

	mini_draw_loop(data, mlx, map);
}
