/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakary <yakary@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 14:45:43 by ycyr-roy          #+#    #+#             */
/*   Updated: 2025/01/14 12:36:37 by yakary           ###   ########.fr       */
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
#define TX_MINI 10
#define MAX_TILES_X 200
#define MAX_TILES_Y 200
#define MAX_PX 12800// (MAX_TILES_X(Y) * TX_SIZE)  pt pu utile
#define SPEED 0.2
#define M_PI_2 1.57079632679489661923
#define M_PI 3.14159265358979323846

#define DEBUG_ON 1
#define TRUE 1
#define FALSE 0
//Chat colors
#define CYAN 0
#define PURPLE 1
#define GREEN 2
#define RED "\033[31m"
#define RESET "\033[0m"

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
	double x;
	double y;
}				t_co;

typedef struct s_cube
{
	mlx_image_t		*image;
	mlx_texture_t	*texture;
}				t_cube;

typedef struct s_3d_assets
{
	t_cube *wall_n;
	t_cube *wall_s;
	t_cube *wall_e;
	t_cube *wall_w;
}				t_3d_assets;

typedef struct s_2d_assets
{
	t_cube *hud;
	t_cube *wall;
	t_cube *player;
	t_cube *mouse;
	mlx_image_t *text_pl_coo;
	mlx_image_t *text_angle; //tmp
	mlx_win_cursor_t *cursor;
}				t_2d_assets;

typedef struct s_map
{
	char map[MAX_TILES_Y][MAX_TILES_X];
	char *file;
	int width;
	int height;
	t_co start;
	t_co end;

	
}				t_map;

typedef struct s_player
{
	t_co co; //tile * tx_size
	t_co m_co;
	double angle;
	int dir;
	
}				t_player;

typedef struct data
{
	void *mlx;
	t_map *map;
	t_memblock *memblock;
	t_player 	player;
	t_3d_assets	a3d;
	t_2d_assets	a2d;
	t_co		scr_co; //for internal use, coos on screen
	bool 		texture_created;
}				t_data;





//==================Prototypes=================//
//utils.c
t_data		*get_data(void);
int 		find_char(char **arr, char c);
int			is_empty_line(char *line);
int			char_in_map(char map[MAX_TILES_X][MAX_TILES_Y], char c);
//init.c
void		init(char **argv, int argc);
int 		init_map_prefix(char **map);
//parsing.c
void		parse_main(char *str);
int			is_map_legal(t_map *map);
int			parse_file_name(char *str);
void		parse_map(int fd, t_data *data, int x, int y);
//utils_test.c
int			debug(void);
void 		print_array(char **arr);
void		print_map(t_map *map);
void 		print_co(t_co co, char *name, int color);
//error_handler.c
void		fatal_error(char *str);
int			soft_error(char *str);
void		ft_mlx_error(void);
//garbage_tools.c
void		*gc_malloc(size_t size);
void		*gc_calloc(size_t count, size_t size);
char		*gc_strjoin(char *s1, char *s2);
char		**gc_split(char *str, char c);

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
void		mv_cursorhook(double xpos, double ypos, void* param);
//minimap.c
void		draw_minimap(t_data *data, mlx_t *mlx, t_map *map);
void load_minimap(t_data *data, mlx_t *mlx, t_map *map);
//textures.c
void		texture_handler();
void		texture_load_all(t_data *data);
//texture_utils.c
mlx_texture_t	*texture_inject(void *ptr);
mlx_image_t		*texture_load(mlx_t *mlx, mlx_texture_t *texture);
void			put_on_screen(mlx_image_t *image, int x, int y, char *name);
//reload.c
void		reload(void);
int			load_assets(t_data *data, mlx_t *mlx);
int			unload_assets(t_data *data, mlx_t *mlx);
//collision.c
int			can_move(t_data *data, double angle);

#endif