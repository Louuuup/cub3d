/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:13:25 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/04 11:03:43 by yakary           ###   ########.fr       */
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

void print_co(t_co co, char *name, int color)
{
	if (debug())
	{
		if (color == CYAN)
			printf("Coordinates of \033[33m[%s]\033[0m: \033[36m(%.1f; %.1f)\033[0m\n", name, co.x, co.y);
		else if (color == PURPLE)
			printf("Coordinates of \033[33m[%s]\033[0m: \033[35m(%.1f; %.1f)\033[0m\n", name, co.x, co.y);
		else
			printf("Coordinates of \033[33m[%s]\033[0m: \033[32m(%.1f; %.1f)\033[0m\n", name, co.x, co.y);

	}
}