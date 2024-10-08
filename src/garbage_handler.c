/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:14:28 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/21 16:14:03 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_memblock	*memblock_create(void *ptr)
{
	t_memblock	*memblock;

	memblock = ft_calloc(1, sizeof(t_memblock));
	if (!memblock)
	{
		soft_error("malloc error\n");
		return (NULL);
	}
	memblock->ptr = ptr;
	memblock->next = NULL;
	return (memblock);
}

t_memblock	*memblock_add(t_memblock *memblock, void *ptr)
{
	t_memblock	*new;

	if (!memblock)
	{
		if (debug())
			printf("memblock is NULL\n");
		return (memblock_create(ptr));
	}
	new = ft_calloc(1, sizeof(t_memblock));
	new->ptr = ptr;
	new->next = memblock;
	return (new);
}

void	gc_free_all(t_memblock *memblock)
{
	t_memblock	*tmp;

	while (memblock)
	{
		tmp = memblock->next;
		free(memblock->ptr);
		free(memblock);
		memblock = tmp;
	}
}

void	gc_free_one(t_memblock *memblock, void *ptr)
{
	t_memblock	*tmp;
	t_memblock	*prev;

	tmp = memblock;
	prev = NULL;
	while (tmp)
	{
		if (tmp->ptr == ptr)
		{
			if (prev)
				prev->next = tmp->next;
			else
				memblock = tmp->next;
			free(tmp->ptr);
			free(tmp);
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
