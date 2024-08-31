/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:52:29 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/23 13:42:59 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	exit_cub3d(t_data *data)
{
	(void)data;
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_release(int key, t_data *data)
{
	data->key[key] = false;
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == esc)
		exit_cub3d(data);
	else if (key == p)
		data->pause = !data->pause;
	if (data->pause || data->game_over)
		return (0);
	if (key == e)
		change_door_state(data, &data->player_pos, data->player_angle);
	data->key[key] = true;
	return (0);
}
