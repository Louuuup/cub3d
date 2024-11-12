/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:59:30 by yakary            #+#    #+#             */
/*   Updated: 2024/11/12 14:46:00 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//Bin attends, ca arrive bientot. Ici on va mettre tout le loading de textures (et 3d et minimap), inlcuant l'unload.
//La main function ici sera call a chaque input (bouger, tourner, etc) pour recharger les textures en fonction de la direction du joueur.

//puts visuals (images) on screen. Called by reload each time the player moves
int load_assets(t_data *data, mlx_t *mlx)
{
    (void)data;
    (void)mlx;
    texture_handler();
    load_minimap(data, mlx, data->map);
    return NO_ERROR;
    
}

int unload_assets(t_data *data, mlx_t *mlx)
{   
    mlx_delete_image(mlx, data->a2d.wall->image);
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