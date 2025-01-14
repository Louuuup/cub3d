/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:59:30 by yakary            #+#    #+#             */
/*   Updated: 2025/01/14 12:05:33 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//Bin attends, ca arrive bientot. Ici on va mettre tout le loading de textures (et 3d et minimap), inlcuant l'unload.
//La main function ici sera call a chaque input (bouger, tourner, etc) pour recharger les textures en fonction de la direction du joueur.

static void load_extra_texts(t_data *data, mlx_t *mlx)
{
    char *tmp;
    char *tmp2;

    if (data->a2d.text_angle)
        mlx_delete_image(mlx, data->a2d.text_angle);
    tmp = ft_dtoa(data->player.angle, 0);
    tmp2 = ft_strjoin("ANGLE: ", tmp);
    free(tmp);
    tmp = ft_strjoin(tmp2, "°");
    free(tmp2);
    data->a2d.text_angle = mlx_put_string(mlx, tmp, 1640, 30);
    free(tmp);
}


static void load_texts(t_data *data, mlx_t *mlx)
{
    char *tmp;
    char *tmp2;
    if (data->a2d.text_pl_coo)
        mlx_delete_image(mlx, data->a2d.text_pl_coo);
    tmp = ft_dtoa(data->player.co.x, 0);
    printf("Player co x: %f\n", data->player.co.x);
    printf("tmp(x): %s\n", tmp); 
    tmp2 = ft_strjoin("PLAYER: (", tmp);
    free(tmp);
    tmp = ft_strjoin(tmp2, ";");
    free(tmp2);
    tmp2 = ft_itoa(data->player.co.y);
    tmp = ft_strjoin(tmp, tmp2);
    free(tmp2);
    tmp2 = ft_strjoin(tmp, ")");
    free(tmp);
    data->a2d.text_pl_coo = mlx_put_string(mlx, tmp2, 1640, 10);
    free(tmp2);
    load_extra_texts(data, mlx);
}

//puts visuals (images) on screen. Called by reload each time the player moves
int load_assets(t_data *data, mlx_t *mlx)
{
    (void)data;
    (void)mlx;
    texture_handler();
    load_minimap(data, mlx, data->map);
    load_texts(data, mlx);
    return NO_ERROR;
    
}

int unload_assets(t_data *data, mlx_t *mlx)
{   
    mlx_delete_image(mlx, data->a2d.wall->image);
    mlx_delete_image(mlx, data->a2d.text_pl_coo);
    mlx_delete_image(mlx, data->a2d.text_angle);
    data->a2d.wall->image = NULL;
    return NO_ERROR;
}

void reload(void)
{
    t_data *data;

    data = get_data();
    unload_assets(data, data->mlx);
    load_assets(data, data->mlx);

}