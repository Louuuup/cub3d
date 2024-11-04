/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:43:57 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/04 15:40:59 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void mini_draw(char c, t_co co)
{
	if (c == '0')
	{
		printf("Floor\n");
		print_co(co, "Floor", PURPLE);

	}
	else if (c == '1')
	{
		printf("Wall\n");
		print_co(co, "Wall", PURPLE);
		put_on_screen(get_data()->map->wall->image, co.x, co.y, "WALL");
	}
	else
	{
		printf("Error: %c\n", c);
		if (debug())
		{
			t_co tmp;
			tmp.x = co.x;
			tmp.y = co.y;
			print_co(tmp, "COULDNT PRINT", CYAN);
		}
	}

}

// static void old_mini_draw_loop(t_data *data, mlx_t *mlx, t_map *map)
// {
// 	t_co co;
// 	t_co max;

// 	(void)mlx;
// 	co.y = data->player.co.y - 9.5; //why those numbers?
// 	max.y = co.y + 20; //why those numbers?
// 	data->scr_co.y = map->start.y /*+ (data->player.co.y)*/;
// 	print_co(data->scr_co, "minimap start", CYAN);
// 	print_co(co, "Grid start", PURPLE);
// 	print_co(max, "Max grid", PURPLE);
// 	print_map(map);
// 	while (co.y < max.y)
// 	{
// 		co.x = data->player.co.x - 9.5;
// 		max.x = co.x + 20;
// 		data->scr_co.x = map->start.x /*+ (data->player.co.x)*/;
// 		while (co.x < max.x)
// 		{
// 			printf("Reading '%c' at %f, %f\n", map->map[(int)co.y][(int)co.x], co.x, co.y);
// 			if (co.x >= 0 && co.y >= 0 && co.x < map->width && co.y < map->height)
// 				mini_draw(map->map[(int)co.y][(int)co.x], data->scr_co);
// 			else
// 				print_co(co, "Out of bounds", CYAN);			
// 			co.x++;
// 			data->scr_co.x += MINI_SCALE;
// 		}
// 		co.y++;
// 		data->scr_co.y += MINI_SCALE;
// 	}

// }
//recoding the function
static void mini_draw_loop(t_data *data, mlx_t *mlx, t_map *map)
{
	// t_co map_co;
	(void)mini_draw;
	t_co px_co;
	t_co temp;

	temp.x = 0;
	temp.y = 0;
	px_co = map->start;
	(void)mlx;
	(void)data;
	if (debug())
		printf("Drawing minimap\n");

	while (temp.y < 30)
	{
		while (temp.x < 30)
		{
			if ((int)px_co.x % 20)
				put_on_screen(map->wall->image, px_co.x, px_co.y, "WALL");
			px_co.x += 10;
			temp.x++;
		}
		px_co.x = map->start.x;
		px_co.y += 10;
		temp.y++;
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
