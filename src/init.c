/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:55:21 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/21 16:10:05 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	mlx = mlx_init(WIDTH, HEIGHT, "Cub3D prototype, V0.01", false);
	data->mlx = mlx;
	
}

void	map_read(int fd, t_data *data, int x, int y)
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