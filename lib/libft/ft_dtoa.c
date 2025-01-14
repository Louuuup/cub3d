/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:32:53 by yakary            #+#    #+#             */
/*   Updated: 2024/12/14 23:53:07 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

// Converts a DOUBLE to its CHAR equivalent.
char *ft_dtoa(double n, int precision)
{
    char *out;
    char *tmp;
    size_t len;

    tmp = ft_itoa((int)n);
    len = ft_strlen(tmp) + 1 + precision + 1;
    free(tmp);
    out = (char *)malloc(len);
    if (!out)
        return NULL;
    while (precision--)
        n *= 10;
    
}