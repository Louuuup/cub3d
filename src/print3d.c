/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:00:21 by alex              #+#    #+#             */
/*   Updated: 2024/11/19 16:21:59 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* typedef struct s_3d_assets
{
	t_cube *wall_n;
	t_cube *wall_s;
	t_cube *wall_e;
	t_cube *wall_w;
}				t_3d_assets;


typedef struct data
{
	void *mlx;
	t_map *map;
	t_memblock *memblock;
	t_player 	player;
	t_3d_assets	a3d;
	t_2d_assets	a2d;
	t_co		scr_co; //for internal use, coos on screen
}				t_data;



steps to draw:
1. top half screen ceiling color, bottom half floor color
2. raycasting
3. draw walls from raycasting
*/



/* 
void	put_ceiling_floor(ceiling colors, floor colors)
{
	int	y;
	int	x;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				ft_put_pixel(/*mlx image, x, y, /*ceiling colors);
			else
				ft_put_pixel(/*mlx image, x, y, /*floor colors);
            x++;
		}
        y++;
	}
}



void	draw_wall(t_data *data)
{
	int	x = 0;
	int			start;
	int			end;
    int         lineHeight;
    int drawStart;
    int drawEnd;

	lineHeight = (int)(HEIGHT/ perpWallDist);
	drawStart = -lineHeight / 2 + HEIGHT / 2;
	if (drawStart < 0)
		start = 0;
    drawEnd = lineHeight / 2 + HEIGHT / 2;
    if(drawEnd >= HEIGHT) 
        drawEnd = HEIGHT - 1;

    
	while (drawStart < drawEnd)
	{
        //from raydirection X being  < 0 or not = draw North or south
        //from raydirection y being < 0 or not = draw East or West
        //put pixel of either North, SOuth East or West
		//(find how to draw specific texture of file)
		drawStart++;
	}
	x++;
}

void draw_all(t_data *data)
{
    put_ceiling_floor(/*colors, /*colors);
    raycasting();
    draw_wall(data);
}  */