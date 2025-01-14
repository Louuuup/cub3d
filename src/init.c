/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:55:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/12/13 15:24:55 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_ptr(t_data *data)
{
	data->a2d.wall = (t_cube *)gc_calloc(1, sizeof(t_cube));
	data->a2d.wall = (t_cube *)gc_calloc(1, sizeof(t_cube));
	data->a2d.player = (t_cube *)gc_calloc(1, sizeof(t_cube));
	data->a2d.hud = (t_cube *)gc_calloc(1, sizeof(t_cube));
	data->a2d.mouse = (t_cube *)gc_calloc(1, sizeof(t_cube));
	data->a3d.wall_n = (t_cube *)gc_calloc(1, sizeof(t_cube));
	data->a3d.wall_s = (t_cube *)gc_calloc(1, sizeof(t_cube));
	data->a3d.wall_e = (t_cube *)gc_calloc(1, sizeof(t_cube));
	data->a3d.wall_w = (t_cube *)gc_calloc(1, sizeof(t_cube));
	
	
}

static void init_rd_txt(t_data * data, char *str)
{
	if (strncmp(str, "NO ", 3) == 0)
		data->a3d.wall_n->texture = texture_inject(str + 3);
	else if (strncmp(str, "SO ", 3) == 0)
		data->a3d.wall_s->texture = texture_inject(str + 3);
	else if (strncmp(str, "WE ", 3) == 0)
		data->a3d.wall_w->texture = texture_inject(str + 3);
	else if (strncmp(str, "EA ", 3) == 0)
		data->a3d.wall_e->texture = texture_inject(str + 3);
	else if (strncmp(str, "F ", 2) == 0)
		; //floor color
	else if (strncmp(str, "C ", 2) == 0)
		; //ceiling color
	else
		fatal_error("Invalid map file");
}

//Skips empty lines and handles file prefix. Returns the line where grid starts, or -1 if map is invalid
int init_map_prefix(char **map)
{
	int i;
	char **split;

	i = 0;
	while (split[i][0] != '1' || split[i][0] != '0')
	{
		while (is_empty_line(split[i]))
			i++;
		if (split[i][0] == 'F' || split[i][0] == 'C' || split[i][0] == 'N' || split[i][0] == 'S' || split[i][0] == 'W' || split[i][0] == 'E')
			init_rd_txt(get_data(), split[i]);
		else if (split[i][0] == '1' || split[i][0] == '0')
			break;
		else
			fatal_error(gc_strjoin("Invalid map file: ", split[i]));
		i++;
	}
	
	return (i);
}
void	init(char **argv, int argc)
{
	mlx_t *mlx;
	t_data *data;

	data = get_data();
	if (argc != 2)
		fatal_error("Only one argument is allowed");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4) != 0)
		fatal_error("Invalid file extension");
	else 
		printf("File extension is valid\n");
	data->map = (t_map *)gc_calloc(1, sizeof(t_map));
	if (parse_file_name(argv[1]))
		fatal_error("Invalid file name");
	data->map->height = MAX_TILES_Y;
	data->map->width = MAX_TILES_X;
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D prototype, V0.01", false);
	data->mlx = mlx;
	data->player.co.x = 0;
	data->player.co.y = 0;
	data->a2d.text_pl_coo = NULL;
	data->player.m_co.x =  WIDTH - (MINI_SCALE * 30 / 2);
	data->player.m_co.y = (MINI_SCALE * 30 / 2);
	data->player.dir = 0;
	data->map->start.x = WIDTH - (MINI_SCALE * 30);
	data->map->start.y = 0;
	data->map->end.x = WIDTH - MINI_SCALE;
	data->map->end.y = (MINI_SCALE * 30) - MINI_SCALE;
	data->texture_created = FALSE;
	init_ptr(data);
}
