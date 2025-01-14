/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:56:05 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/11/25 17:03:20 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

//Checks if a line is empty. Returns 1 if it is, 0 if not
int is_empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

//counts the amount of 'c' in array of strings
int find_char(char **arr, char c)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (arr[i])
	{
		if (ft_strchr(arr[i], c))
			count++;
		i++;
	}
	return (count);
}

int char_in_map(char map[MAX_TILES_X][MAX_TILES_Y], char c)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while (i <= MAX_TILES_Y)
	{
		if (ft_strchr(map[i], c))
			count++;
		i++;
	}
	return (count);
}