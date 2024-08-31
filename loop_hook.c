/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 20:08:53 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 15:08:12 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include "mlx_opengl/mlx.h"

#include <math.h>
#include <stdlib.h>

static void	draw_white_screen(t_data *data)
{
	const t_ipos	dot_pos = {0, 0};
	const t_ipos	dot_size = {WIDTH, HEIGHT};

	draw_square(&data->img, &dot_pos, &dot_size, WHITE);
}

static void	draw_left_keys(t_data *data)
{
	char	*num;
	char	*str;

	num = ft_itoa(data->key_left);
	if (num == NULL)
		exit(EXIT_FAILURE);
	str = ft_strjoin("LEFT KEYS: ", num);
	if (str == NULL)
		exit(EXIT_FAILURE);
	free(num);
	mlx_string_put(data->mlx, data->win, 20, 280, RED, str);
	free(str);
	if (data->key_left == 0)
	{
		mlx_string_put(data->mlx, data->win, 20, 300,
			RED, "NOW YOU CAN ESCAPE!!");
	}
}

static void	put_images(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win,
		data->minimap_background_img.img, 10, 10);
	mlx_put_image_to_window(data->mlx, data->win,
		data->minimap_wall_img.img, 10, 10);
	draw_left_keys(data);
}

static void	draws(t_data *data)
{
	int	i;

	draw_white_screen(data);
	ray_casting(data);
	draw_minimap(data);
	draw_rays(data);
	i = -1;
	while (++i < data->sprite_num)
		draw_sprite(data, &data->sprite[i]);
	draw_stamina_bar(data);
}

int	loop_hook(t_data *data)
{
	if (data->game_over)
		return (0);
	data->frame++;
	if (data->frame == 30)
		data->frame = 0;
	if (data->pause)
	{
		mlx_mouse_show();
		return (0);
	}
	else
		mlx_mouse_hide();
	enemy_move(data);
	mlx_mouse_move(data->win, WIDTH / 2, HEIGHT / 2);
	progress_door_state(data);
	move(data);
	draws(data);
	if (data->game_over)
		return (0);
	sort_sprite(data);
	put_images(data);
	return (0);
}
