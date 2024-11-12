/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:05:46 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/12 15:20:15 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*texture_inject(void *ptr)
{
	mlx_texture_t *texture;

	texture = NULL;
	if (debug())
		printf("Creating texture from '%s'\n", (char *)ptr);
	if (access(ptr, F_OK) == -1)
		fatal_error("Texture file not found");
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