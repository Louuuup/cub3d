/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:05:46 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/04 11:03:26 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*texture_inject(mlx_texture_t *texture, void *ptr)
{
	texture = mlx_load_png(ptr);
	//ptr to free?
	if (!texture)
		ft_mlx_error();
	return (texture);
}

mlx_image_t	*texture_load(mlx_t *mlx, mlx_texture_t *texture)
{
	mlx_image_t	*image;

	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		ft_mlx_error();
	return (image);
}

void put_on_screen(mlx_image_t *image, int x, int y, char *name)
{
	t_co co;

	co.x = x;
	co.y = y;
	print_co(co, name, GREEN);
	mlx_image_to_window(get_data()->mlx, image, x, y);

}