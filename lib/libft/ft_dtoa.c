/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:32:53 by yakary            #+#    #+#             */
/*   Updated: 2025/01/14 12:13:54 by yakary           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"

// Converts a DOUBLE to its CHAR equivalent.
static char *convert_integer_part(double n);
static char *convert_fractional_part(double n, int precision);

// Converts a DOUBLE to its CHAR equivalent.
char *ft_dtoa(double n, int precision)
{
    size_t len;
    char *out;
    char *int_part_str;
    int_part_str = convert_integer_part(n);
    if (!int_part_str)
        return NULL;
    char *frac_part_str = convert_fractional_part(n, precision);
    if (!frac_part_str)
    {
        free(int_part_str);
        return NULL;
    }
    len = ft_strlen(int_part_str) + ft_strlen(frac_part_str) + 1;
    out = (char *)malloc(len);
    if (!out)
    {
        free(int_part_str);
        free(frac_part_str);
        return NULL;
    }
    ft_strlcpy(out, int_part_str, len);
    ft_strlcat(out, frac_part_str, len);
    free(int_part_str);
    free(frac_part_str);
    return out;
}

static char *convert_integer_part(double n)
{
    return ft_itoa((int)n);
}

static char *convert_fractional_part(double n, int precision)
{
    double frac_part = fabs(n - (int)n);
    char *frac_part_str = (char *)malloc(precision + 2); // +1 for '.' and +1 for '\0'
    if (!frac_part_str)
        return NULL;
    frac_part_str[0] = '.';
    for (int i = 1; i <= precision; i++)
    {
        frac_part *= 10;
        frac_part_str[i] = ((int)frac_part % 10) + '0';
    }
    frac_part_str[precision + 1] = '\0';
    return frac_part_str;
}