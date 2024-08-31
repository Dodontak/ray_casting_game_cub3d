/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:43:17 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 15:28:43 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//rays
# define RAY_NUM 360
# define FOV 60.0
# define MAX_DISTANCE 2e9
//minimaps
# define MINIMAP_WALL_SIZE 16
# define MINIMAP_VIEW_RANGE 7
# define COLLISON_BOX 0.125f
# define CUBE_LEN 8
//graphics
# define HEIGHT 720
# define WIDTH 1280
# define PER_BYTE 8
# define FPS 60
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define VIOLET 0x008F00FF
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define DARK_VIOLET 0x00940080
# define DARK_GREEN 0x00004008
# define BRIGHT_GREEN 0x0000A014
# define CLEAR 0xFF000000
//mlx_actions
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MOUSE_MOVE 6
# define EXIT_CLICK 17
//math constants
# define D_ANGLE 0.05
# define PI 3.14159265359
# define DEGREE 0.0174533
//game configs
# define MOUSE_SENSITIVITY 0.1
# define MOVE_CONST 0.08
# define WALL_ST_CONST 20
# define ANGLE_SPEED 80
# define ENEMY_MOVE 0.8
# define ENEMY_FRAME 10
// # include <mlx.h>
# include <stdbool.h>
# include <stdlib.h>
# include "mlx_opengl/mlx.h"

typedef enum e_key
{
	w = 13,
	s = 1,
	a = 0,
	d = 2,
	p = 35,
	e = 14,
	left = 123,
	right = 124,
	down = 125,
	up = 126,
	esc = 53,
	shift = 257
}	t_key;

typedef enum e_map_symbols
{
	m_empty = '0',
	m_wall = '1',
	m_door = 'D',
	m_north = 'N',
	m_west = 'W',
	m_south = 'S',
	m_east = 'E'
}	t_map_symbols;

typedef struct s_ipos
{
	int	x;
	int	y;
}	t_ipos;

typedef struct s_fpos
{
	double	x;
	double	y;
}	t_fpos;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_img;

typedef enum e_sprite_type
{
	s_null = 'R',
	s_enemy = 'M',
	s_key = 'K',
	s_escape = 'X'
}	t_sprite_type;

typedef struct s_sprite
{
	t_fpos			pos;
	t_sprite_type	type;
	t_img			*texture;
	int				num_of_texture;
	double			angle;
	double			dist;
}	t_sprite;

typedef struct s_wall
{
	double			tex_y;
	double			x_off;
	int				y_off;
	double			dist;
	double			normal_angle;
	double			ratio;
	int				height;
	unsigned int	color;
	t_fpos			ray;
	t_ipos			st;
	t_ipos			ed;
	t_ipos			texture_pos;
	t_img			*texture;
}	t_wall;

typedef struct s_ray
{
	int		index;
	int		texture_color;
	bool	hit_door_v;
	bool	hit_door_h;
	t_fpos	horiznal;
	t_fpos	vertical;
	t_fpos	dv;
	t_fpos	dh;
	t_ipos	map_v;
	t_ipos	map_h;
	t_fpos	hit;
	double	vertical_dist;
	double	horiznal_dist;
	double	shortest_dist;
	double	angle;
	double	ratio;
}	t_ray;

typedef struct s_door
{
	struct s_door	*next;
	t_ipos			mpos;
}	t_door;

typedef struct s_door_list
{
	t_door	*head;
	t_door	*tail;
}	t_door_list;

typedef enum e_door_state
{
	d_close,
	d_open
}	t_door_state;

typedef enum e_env_type
{
	e_empty,
	e_wall,
	e_closed_door,
	e_opened_door,
	e_trans_door,
	e_sprite,
	e_key
}	t_env_type;

typedef struct s_env
{
	t_env_type		type;
	double			door_ratio;
	t_door_state	last_state;
	t_sprite		sprite;
}	t_env;

typedef struct s_map
{
	char		**map;
	int			map_x_len;
	int			map_y_len;
	int			player_x;
	int			player_y;
	int			floor_color;
	int			ceiling_color;
	char		*texture_path[4];
}	t_map;

typedef enum e_pq_direction
{
	p_north,
	p_north_west,
	p_west,
	p_west_south,
	p_south,
	p_south_east,
	p_east,
	p_east_north,
	p_zero
}	t_pq_direction;

typedef struct s_pq_node
{
	t_fpos			pos;
	t_pq_direction	dir;
	t_sprite		*addr;
	double			score;
	double			dist;
}	t_pq_node;

typedef struct s_pq
{
	t_pq_node	**min_heap;
	int			heap_size;
	int			heap_capacity;
	bool		**visit;
}	t_pq;

typedef enum e_texture_index
{
	ti_north,
	ti_south,
	ti_west,
	ti_east,
	ti_door,
	ti_door_side,
	ti_lose,
	ti_win
}	t_texture_index;

typedef struct s_sprite_arg
{
	t_ipos	modified_size;
	t_ipos	draw_point;
	t_ipos	start;
	t_ipos	center;
	t_ipos	tex_size;
	t_ipos	img_d;
	double	tex_dy;
	int		tex_no;
}	t_sprite_arg;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_fpos		player_pos;
	t_fpos		enemy_pos;
	int			enemy_frame;
	int			key_left;
	double		player_angle;
	int			wall_st;
	t_map		map;
	bool		key[300];
	bool		pause;
	bool		interaction;
	bool		is_exhausted;
	bool		game_over;
	t_img		textures[8];
	t_ray		ray[RAY_NUM];
	t_env		**env_map;
	t_door_list	door_list;
	t_img		minimap_background_img;
	t_img		minimap_wall_img;
	t_sprite	*sprite;
	t_img		escape;
	t_img		key_img;
	t_img		*enemy;
	int			stamina;
	int			sprite_num;
	int			frame;
}	t_data;

//init_data.c
void			init_data(t_data *data, int ac, char **av);
//priority_queue.c
void			pq_init(t_data *data, t_pq *pq);
void			pq_free(t_data *data, t_pq *pq);
void			pq_push(t_pq *pq, t_pq_node *new);
t_pq_node		*pq_pop(t_pq *pq);
//change_door_state.c
void			change_door_state(t_data *data, t_fpos *pos, double angle);
bool			enemy_change_door(t_data *data, t_fpos *pos, t_fpos *d);
//progress_door_state.c
void			progress_door_state(t_data *data);
//move.c
void			move(t_data *data);
//enemy_move.c
void			enemy_move(t_data *data);
//loop_hook.c
int				loop_hook(t_data *data);
//key_hook.c
int				exit_cub3d(t_data *data);
int				key_press(int key, t_data *data);
int				key_release(int key, t_data *data);
//mouse_hook.c
int				mouse_hook(int x, int y, t_data *data);
//draws.c
void			draw_circle(t_img *img, t_ipos *center,
					int r, const unsigned int color);
void			draw_square(t_img *img, const t_ipos *st,
					const t_ipos *ed, const unsigned int color);
void			draw_line(t_img *img, const t_ipos *st,
					const t_ipos *ed, const unsigned int color);
void			pixel_put(t_img *img, t_ipos pos, const unsigned int color);
//ray_casting.c
void			ray_casting(t_data *data);
//ray_casting2.c
void			check_horizontal_ray(t_data *data, t_ray *ray);
void			check_vertical_ray(t_data *data, t_ray *ray);
//draw_rays.c
void			draw_rays(t_data *data);
//draw_wall.c
void			draw_wall(t_data *data, t_ray *ray);
//draw_minimap.c
void			draw_minimap(t_data *data);
void			set_minimap_img(t_data *data);
void			draw_circle(t_img *img, t_ipos *center, int r,
					const unsigned int color);
void			pixel_put_in_map(t_img *img, t_ipos pos,
					const unsigned int color);
void			fill_clear_pixel(t_img *img, int size_x, int size_y);
//draw_stamina_bar.c
void			draw_stamina_bar(t_data *data);
//set_wall.c
void			set_wall(t_data *data, t_ray *ray, t_wall *wall);
//utils.c
void			angled_moving(t_fpos *pos, double range, double angle);
unsigned int	get_texture_color(t_img *img, t_ipos pos);
double			get_euclidian_dist(const t_fpos *st, const t_fpos *ed);
void			*safe_malloc(size_t size);
void			init_img(t_img *img, t_data *data);
//is_in_circle.c
bool			is_in_circle(t_ipos *point, int center_x, int center_y, int r);
//draw_sprites.c
void			draw_sprite(t_data *data, t_sprite *sprite);
//game_over.c
void			game_over(t_data *data, bool is_win);
//sort_sprite.c
void			set_sprites(t_data *data);
void			sort_sprite(t_data *data);

#endif
