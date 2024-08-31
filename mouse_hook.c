/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:58:02 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/22 20:25:03 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_hook(int x, int y, t_data *data)
{
	const int	dx = x - WIDTH / 2;

	if (data->pause)
		return (0);
	data->wall_st += y - HEIGHT / 2;
	if (data->wall_st > HEIGHT)
		data->wall_st = HEIGHT;
	else if (data->wall_st < 0)
		data->wall_st = 0;
	data->player_angle -= dx * DEGREE * MOUSE_SENSITIVITY;
	if (data->player_angle > 2 * PI)
		data->player_angle -= 2 * PI;
	else if (data->player_angle < 0)
		data->player_angle += 2 * PI;
	return (0);
}
