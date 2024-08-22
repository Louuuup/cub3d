/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:21:34 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/22 14:29:50 by ycyr-roy         ###   ########.fr       */
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
	if (debug())
		printf("Launching loop\n");
	mlx_loop(data->mlx);
	if (debug())
		printf("Terminating mlx\n");
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}