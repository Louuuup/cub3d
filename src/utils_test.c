/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:13:25 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/22 12:28:12 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	printf("Printing map\n");
	while (i < map->height && map->map[i][0] != '\0')
	{
		j = 0;
		while (j < map->width && map->map[i][j] != '\0')
		{
			printf("%c", map->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	if (debug())
		printf("Map printed\n");
}

int debug(void)
{
	if (DEBUG_ON)
	{
		printf(DEBUG_MSG);
		return (TRUE);
	}
	return (FALSE);
}