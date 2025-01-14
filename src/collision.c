/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:33:53 by yakary            #+#    #+#             */
/*   Updated: 2024/12/13 14:38:17 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int can_move(t_data *data, double angle)
{
    t_co new_co;

    new_co.x = data->player.co.x + cos(angle) * SPEED;
    new_co.y = data->player.co.y + sin(angle) * SPEED;
    if (new_co.x < 0 || new_co.y < 0 || new_co.x > data->map->width || new_co.y > data->map->height)
        return FALSE;
    if (data->map->map[(int)new_co.y][(int)new_co.x] == '1')
        return FALSE;
    return TRUE;
}