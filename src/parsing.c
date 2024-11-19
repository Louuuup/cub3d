/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:31:07 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/19 14:57:28 by alex             ###   ########.fr       */
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

// Checks if map is legal, and offsets player in middle of its tile  -  Returns 0 if map is legal, 1 if not
int	is_map_legal(t_map *map)
{
	int i;
	int j;

	i = 0;
	if (debug())
		printf("Checking if map is valid...\n");
	while (i < map->height && map->map[i][0] != '\0')
	{
		j = 0;
		while (j < map->width && map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
			{
				map->map[i][j] = '0';
				get_data()->player.co.y = i + 0.5;
				// get_data()->player.co.x = (i * TX_SIZE) - (TX_SIZE / 2);
				get_data()->player.co.x = j + 0.5;
				// get_data()->player.co.y = (j * TX_SIZE) - (TX_SIZE / 2);
				print_co(get_data()->player.co, "Player co", PURPLE);
			}
			else if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != '2' && map->map[i][j] != ' ')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// Parses the main file
void parse_main(char *str)
{
	int fd;
	
	fd = -1;
	if (debug())
		printf("Parsing\n");
	fd = open(str, O_RDONLY);
	if (fd < 0)
		fatal_error("Invalid file descriptor");
	parse_map(fd, get_data(), 0, 0);
	if (debug())
		print_map(get_data()->map);
	close(fd);
	
	if (is_map_legal(get_data()->map))
		fatal_error("Invalid map");
	if (debug())
		printf("Map is valid\n");
}