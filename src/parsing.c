/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:31:07 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/12/03 13:55:34 by yakary           ###   ########.fr       */
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
	char	**map;

	if (debug())
		printf("Parsing map\n");
	if (fd < 0)
	{
		printf("Error\n");
		exit(1);
	}
	ft_bzero(buffer, MAX_TILES_X * MAX_TILES_Y);
	if (read(fd, buffer, MAX_TILES_X * MAX_TILES_Y) < 0)
		fatal_error("Error reading file");
	map = gc_split(buffer, '\n');
	i = init_map_prefix(map);
	while (i < MAX_TILES_Y)
	{
		if (map[i][0] == '\0')
			break;
		ft_strlcpy(data->map->map[i], map[i], MAX_TILES_X);
		i++;
		
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
				get_data()->player.co.y = i + 0.5;
				get_data()->player.co.x = j + 0.5;
				print_co(get_data()->player.co, "Player co", PURPLE);
			}
			else if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != '2' \
			 && map->map[i][j] != ' ' || char_in_map(map->map, 'P') != 1)
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
