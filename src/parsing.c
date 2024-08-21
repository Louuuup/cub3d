/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:31:07 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/21 16:12:58 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_file_name(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'b' || str[i - 2] != 'u' || str[i - 3] != 'c' || str[i - 4] != '.')
		return (1);
	get_data()->map->file = str;
	if (debug())
		printf("File name is: %s\n", str);
	return (0);
}

void parse_map(int fd, t_data *data, int x, int y)
{
	
	char	buffer[MAX_TILES_X * MAX_TILES_Y];
	int		i;
	int		bytes;

	if (fd < 0)
	{
		printf("Error\n");
		exit(1);
	}
	ft_bzero(buffer, MAX_TILES_X * MAX_TILES_Y);
	i = 0;
	bytes = read(fd, buffer, MAX_TILES_X * MAX_TILES_Y);
	while (y < MAX_TILES_Y)
	{
		x = 0;
		while ((buffer[i] != '\n' && buffer[i] != '\0'))
		{
			data->map->map[y][x] = buffer[i];
			i++;
			x++;
		}
		i++;
		y++;	
	}
}
int	is_map_legal(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != '2')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void parsing_main(char *str)
{
	int fd;
	
	fd = -1;
	if (parse_file_name(str))
		fatal_error("Invalid file name");
	fd = open(str, O_RDONLY);
	if (fd < 0)
		fatal_error("Invalid file descriptor");
	parse_map(fd, get_data(), 0, 0);
	close(fd);
	
	if (is_map_legal(get_data()->map))
		fatal_error("Invalid map");
	
}