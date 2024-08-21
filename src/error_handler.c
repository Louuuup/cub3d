/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:18:49 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/21 15:27:28 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fatal_error(char *str)
{
	printf(ERROR_MSG);
	printf("%s\n", str);
	exit(1);
}

int	soft_error(char *str)
{
	printf(ERROR_MSG);
	printf("%s\n", str);
	return (1);
}
