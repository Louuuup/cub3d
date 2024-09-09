/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adube <adube@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:45:43 by ycyr-roy          #+#    #+#             */
/*   Updated: 2024/09/09 11:33:28 by adube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <MLX42/MLX42.h>
# include <stdio.h>
# include "string.h"
# include <math.h>


//================Base Values================//
#define WIDTH 1920
#define HEIGHT 1080
#define TX_SIZE 64
#define MAX_TILES_X 200
#define MAX_TILES_Y 200
#define DEBUG_ON 1
#define TRUE 1
#define FALSE 0
//=================Minimap values=================//
#define MINI_SCALE 10
#define MINI_SIZE 100
//=================Messages=================//

#define ERROR_MSG "\033[31mError:\033[0m "
#define DEBUG_MSG "\033[33mDebug:\033[0m "
//==================Structures=================//

//chainlist for allocated memory blocks (for garbage collector)
typedef struct s_memblock
{
	void				*ptr;
	struct s_memblock	*next;
}				t_memblock;

typedef struct coords
{
	int x;
	int y;
}				t_co;

typedef struct s_cube
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;
}				t_cube;

typedef struct s_map
{
	char map[MAX_TILES_Y][MAX_TILES_X];
	char *file;
	int width;
	int height;
	double angle;
	t_co start;
	t_co end;
	t_cube *hud;
	t_cube *wall;
	t_cube *player;
	
}				t_map;

typedef struct s_player
{
	t_co co;
	t_co m_co;
	t_cube *mini_tx;
	int dir;
	
}				t_player;

typedef struct data
{
	void *mlx;
	t_map *map;
	t_memblock *memblock;
	t_player player;
}				t_data;





//==================Prototypes=================//
//utils.c
t_data		*get_data(void);
//init.c
void		map_read(int fd, t_data *data, int x, int y);
void		init(char **argv, int argc);
//parsing.c
void		parse_main(char *str);
int			is_map_legal(t_map *map);
int			parse_file_name(char *str);
void		parse_map(int fd, t_data *data, int x, int y);
//utils_test.c
int			debug(void);
void		print_map(t_map *map);
//error_handler.c
void		fatal_error(char *str);
int			soft_error(char *str);
void		ft_mlx_error(void);
//garbage_tools.c
void		*gc_malloc(size_t size);
void		*gc_calloc(size_t count, size_t size);
char		*gc_strjoin(char *s1, char *s2);
//garbage_handler.c
t_memblock	*memblock_create(void *ptr);
t_memblock	*memblock_add(t_memblock *memblock, void *ptr);
void		memblock_free(t_memblock *memblock);
void		memblock_free_all(t_memblock *memblock);
//movements.c
void		mv_right();
void		mv_left();
void		mv_up();
void		mv_down();
//hooks.c
void		mv_keyhook(mlx_key_data_t keydata, void *param);
//minimap.c
void		draw_minimap(t_data *data, mlx_t *mlx, t_map *map);
//textures.c
void		texture_handler();
//texture_utils.c
mlx_texture_t	*texture_inject(mlx_texture_t *texture, void *ptr);
mlx_image_t		*texture_load(mlx_t *mlx, mlx_texture_t *texture);

#endif