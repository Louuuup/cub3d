/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:05:46 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/22 14:41:16 by ycyr-roy         ###   ########.fr       */
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