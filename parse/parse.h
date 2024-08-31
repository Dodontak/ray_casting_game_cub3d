/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:24:34 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 14:12:43 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../cub3d.h"

typedef struct s_mapinfo
{
	char	**rawdata;
	char	***matrix;
	size_t	map_x;
	size_t	map_y;
	int		pos_x;
	int		pos_y;
	char	**map;
	int		map_start_idx;
	char	*texture[6];
	int		color[2][3];
}	t_mapinfo;

# define NORMAL 0
# define ERROR 1

# define C 0
# define F 1
# define NO 2
# define SO 3
# define WE 4
# define EA 5
# define DOOR_TEXTURE "./assets/door.xpm"
# define DOOR_SIDE_TEXTURE "./assets/door_side.xpm"
# define GREEN1_TEXTURE "./assets/Green1.xpm"
# define GREEN2_TEXTURE "./assets/Green2.xpm"
# define GREEN3_TEXTURE "./assets/Green3.xpm"
# define GREEN4_TEXTURE "./assets/Green4.xpm"
# define GREEN5_TEXTURE "./assets/Green5.xpm"
# define GREEN6_TEXTURE "./assets/Green6.xpm"
# define GREEN7_TEXTURE "./assets/Green7.xpm"
# define GREEN8_TEXTURE "./assets/Green8.xpm"
# define KEY_TEXTURE "./assets/key.xpm"
# define LADDER_TEXTURE "./assets/ladder.xpm"
# define YOU_DIE_TEXTURE "./assets/you_died.xpm"
# define WIN_TEXTURE "./assets/win.xpm"

void	parse(int ac, char **av, t_map *map);

void	check_input_error(int ac, char **av);
char	**make_rawdata(char **av);
char	***make_matrix_from_rawdata(char **rawdata);
int		get_map_start_idx_in_matrix(char ***matrix);
void	check_invalid_file(char ***matrix, int map_start_idx);
void	check_invalid_map(char **map);
void	set_texture_names(t_mapinfo *mapinfo);
char	**make_base_map(t_mapinfo *mapinfo);
void	check_and_set_color(t_mapinfo *mapinfo);
void	set_map(t_map *map, t_mapinfo *mapinfo);

void	check_path(char **map, t_mapinfo *mapinfo);
void	set_pos_xy(char **map, t_mapinfo *mapinfo);
void	set_map_xy(t_mapinfo *mapinfo);

int		get_strs_len(char **strs);
int		get_matrix_len(char ***matrix);

int		count_char_in_str(const char *str, char c);

void	free_strs(char **strs);
void	free_matrix(char ***matrix);
void	print_err_and_exit(int type, int exit_code, const char *str);

void	check_invalid_textures(t_mapinfo *mapinfo);

#endif
