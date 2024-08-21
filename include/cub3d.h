/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:45:43 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/08/21 16:13:21 by ycyr-roy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <MLX42/MLX42.h>
# include <stdio.h>


//================Base Values================//
#define WIDTH 1920
#define HEIGHT 1080
#define TX_SIZE 64
#define MAX_TILES_X 200
#define MAX_TILES_Y 200
#define DEBUG_ON 1
#define TRUE 1
#define FALSE 0

#define ERROR_MSG "\033[31mError:\033[0m "
#define DEBUG_MSG "\033[33mDebug:\033[0m "
//==================Structures=================//
typedef struct s_map
{
	char map[MAX_TILES_Y][MAX_TILES_X];
	char *file;
	int width;
	int height;
}				t_map;

//chainlist for allocated memory blocks (for garbage collector)
typedef struct s_memblock
{
	void				*ptr;
	struct s_memblock	*next;
}				t_memblock;


typedef struct data
{
	void *mlx;
	t_map *map;
	t_memblock *memblock;
}				t_data;

typedef struct coords
{
	int x;
	int y;
}				t_co;




//==================Prototypes=================//
//utils.c
t_data	*get_data(void);
//init.c
void	map_read(int fd, t_data *data, int x, int y);
void	init(char **argv, int argc);
//parsing.c
void parsing_main(char *str);
int parse_file_name(char *str);
void parse_map(int fd, t_data *data, int x, int y);
//utils_test.c
int debug(void);
void print_map(t_map *map);
//error_handler.c
void	fatal_error(char *str);
int		soft_error(char *str);
//garbage_tools.c
void	*gc_malloc(size_t size);
void	*gc_calloc(size_t count, size_t size);
char	*gc_strjoin(char *s1, char *s2);
//garbage_handler.c
t_memblock	*memblock_create(void *ptr);
t_memblock	*memblock_add(t_memblock *memblock, void *ptr);
void		memblock_free(t_memblock *memblock);
void		memblock_free_all(t_memblock *memblock);



#endif