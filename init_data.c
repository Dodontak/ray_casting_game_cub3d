/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 13:31:43 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 14:59:02 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include "libft/libft.h"
#include "parse/parse.h"

static void	init_player(t_data *data)
{
	data->player_pos.x = (double)data->map.player_x + 0.5;
	data->player_pos.y = (double)data->map.player_y + 0.5;
	if (data->map.map[data->map.player_y][data->map.player_x] == 'E')
		data->player_angle = PI * 0 / 180;
	else if (data->map.map[data->map.player_y][data->map.player_x] == 'N')
		data->player_angle = PI * 90 / 180;
	else if (data->map.map[data->map.player_y][data->map.player_x] == 'W')
		data->player_angle = PI * 180 / 180;
	else if (data->map.map[data->map.player_y][data->map.player_x] == 'S')
		data->player_angle = PI * 270 / 180;
	data->stamina = 100;
}

static void	fixed_texturs(t_data *data)
{
	t_img	*texture;

	texture = &data->textures[ti_door];
	texture->img = mlx_xpm_file_to_image(data->mlx, "assets/door.xpm",
			&texture->width, &texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_len, &texture->endian);
	texture = &data->textures[ti_door_side];
	texture->img = mlx_xpm_file_to_image(data->mlx, "assets/door_side.xpm",
			&texture->width, &texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_len, &texture->endian);
	texture = &data->textures[ti_lose];
	texture->img = mlx_xpm_file_to_image(data->mlx, "assets/you_died.xpm",
			&texture->width, &texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_len, &texture->endian);
	texture = &data->textures[ti_win];
	texture->img = mlx_xpm_file_to_image(data->mlx, "assets/win.xpm",
			&texture->width, &texture->height);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
			&texture->line_len, &texture->endian);
}

static void	init_textures(t_data *data)
{
	int		i;
	t_img	*texture;

	i = 0;
	while (i < 4)
	{
		texture = &data->textures[i];
		texture->img
			= mlx_xpm_file_to_image(data->mlx, data->map.texture_path[i],
				&texture->width, &texture->height);
		texture->addr
			= mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
				&texture->line_len, &texture->endian);
		i++;
	}
	fixed_texturs(data);
}

static void	init_env_map(t_data *data)
{
	t_ipos	cur;

	data->env_map
		= (t_env **)safe_malloc(data->map.map_y_len * sizeof(t_env *));
	cur.y = 0;
	while (cur.y < data->map.map_y_len)
	{
		data->env_map[cur.y]
			= (t_env *)safe_malloc(data->map.map_x_len * sizeof(t_env));
		ft_memset(data->env_map[cur.y], 0, sizeof(t_env));
		cur.x = 0;
		while (cur.x < data->map.map_x_len)
		{
			if (data->map.map[cur.y][cur.x] == m_wall)
				data->env_map[cur.y][cur.x].type = e_wall;
			else if (data->map.map[cur.y][cur.x] == m_door)
				data->env_map[cur.y][cur.x].type = e_closed_door;
			else
				data->env_map[cur.y][cur.x].type = e_empty;
			cur.x++;
		}
		cur.y++;
	}
}

void	init_data(t_data *data, int ac, char **av)
{
	ft_memset(data, 0, sizeof(t_data));
	parse(ac, av, &data->map);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3d");
	init_env_map(data);
	init_player(data);
	init_textures(data);
	data->wall_st = HEIGHT / 2;
	init_img(&data->img, data);
	set_minimap_img(data);
}
