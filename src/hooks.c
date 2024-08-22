/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 11:09:39 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/22 12:03:59 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mv_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_right();
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_left();
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_up();
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		mv_down();
	else if (keydata.key == MLX_KEY_ESCAPE && (keydata.action == MLX_PRESS \
		|| keydata.action == MLX_REPEAT))
		exit(EXIT_SUCCESS);
}