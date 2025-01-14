/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:14:30 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/12/03 13:59:23 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*gc_malloc(size_t size)
{
	void	*ptr;
	t_data	*data;

	data = get_data();
	ptr = malloc(size);
	if (!ptr)
	{
		soft_error("malloc error\n");
		return (NULL);
	}
	data->memblock = memblock_add(data->memblock, ptr);
	return (ptr);
}

void	*gc_calloc(size_t count, size_t size)
{
	void	*ptr;
	t_data	*data;

	// if (debug())
	// 	printf("(gc_calloc) Allocating %lu bytes\n", count * size);
	data = get_data();
	ptr = ft_calloc(count, size);
	if (!ptr)
	{
		soft_error("malloc error\n");
		return (NULL);
	}
	data->memblock = memblock_add(data->memblock, ptr);
	return (ptr);
}

char	*gc_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		len[2];

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	new_str = gc_calloc(len[0] + len[1] + 1, sizeof(char));
	ft_strlcpy(new_str, s1, len[0] + 1);
	ft_strlcpy(new_str + len[0], s2, len[1] + 1);
	return (new_str);
}

static int count_segments(char *str, char c)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    return count + 1;
}

char **gc_split(char *str, char c)
{
    char **split;
    int i = 0;
    int j = 0;
    int k = 0;
    int len = count_segments(str, c);

    split = gc_calloc(len + 1, sizeof(char *));
    while (str[i])
    {
        if (str[i] == c)
        {
            split[j] = gc_calloc(i - k + 1, sizeof(char));
            ft_strlcpy(split[j], str + k, i - k + 1);
            k = i + 1;
            j++;
        }
        i++;
    }
    split[j] = gc_calloc(i - k + 1, sizeof(char));
    ft_strlcpy(split[j], str + k, i - k + 1);
    return split;
}
