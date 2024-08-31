/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 13:14:23 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/23 15:06:00 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx_opengl/mlx.h"

void	game_over(t_data *data, bool win)
{
	if (!win)
		mlx_put_image_to_window(data->mlx,
			data->win, data->textures[ti_lose].img, 0, 0);
	else
		mlx_put_image_to_window(data->mlx,
			data->win, data->textures[ti_win].img, 0, 0);
	data->game_over = true;
}
