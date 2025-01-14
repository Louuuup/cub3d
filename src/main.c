/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:21:34 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/29 11:46:36 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data *data;
	
	data = get_data();	
	init(argv, argc);
	parse_main(argv[1]);
	texture_handler();
	draw_minimap(data, data->mlx, data->map);
	if (debug())
		printf("Launching keyhook\n");
	mlx_key_hook(data->mlx, mv_keyhook, (void *)data);
	mlx_cursor_hook(data->mlx, mv_cursorhook, (void *)data);
	if (debug())
		printf("Launching loop\n");
	mlx_loop(data->mlx);
	if (debug())
		printf("Terminating mlx\n");
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}