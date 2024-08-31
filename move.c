/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:16:35 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 15:08:33 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

static bool	is_collision(t_env **map, const double x, const double y)
{
	const t_ipos	up_left = {(x - COLLISON_BOX), (y + COLLISON_BOX)};
	const t_ipos	down_left = {(x - COLLISON_BOX), (y - COLLISON_BOX)};
	const t_ipos	up_right = {(x + COLLISON_BOX), (y + COLLISON_BOX)};
	const t_ipos	down_right = {(x + COLLISON_BOX), (y - COLLISON_BOX)};

	if (map[up_left.y][up_left.x].type != e_wall
		&& map[down_left.y][down_left.x].type != e_wall
		&& map[up_right.y][up_right.x].type != e_wall
		&& map[down_right.y][down_right.x].type != e_wall
		&& map[up_left.y][up_left.x].type != e_closed_door
		&& map[down_left.y][down_left.x].type != e_closed_door
		&& map[up_right.y][up_right.x].type != e_closed_door
		&& map[down_right.y][down_right.x].type != e_closed_door
		&& map[up_left.y][up_left.x].type != e_trans_door
		&& map[down_left.y][down_left.x].type != e_trans_door
		&& map[up_right.y][up_right.x].type != e_trans_door
		&& map[down_right.y][down_right.x].type != e_trans_door)
		return (false);
	return (true);
}

static void	arrows(t_data *data)
{
	if (data->key[left])
		data->player_angle += DEGREE * MOVE_CONST * ANGLE_SPEED;
	if (data->key[right])
		data->player_angle -= DEGREE * MOVE_CONST * ANGLE_SPEED;
	if (data->key[up])
		data->wall_st -= HEIGHT / WALL_ST_CONST;
	if (data->key[down])
		data->wall_st += HEIGHT / WALL_ST_CONST;
	if (data->wall_st > HEIGHT)
		data->wall_st = HEIGHT;
	else if (data->wall_st < 0)
		data->wall_st = 0;
	if (data->player_angle < 0)
		data->player_angle += 2 * PI;
	else if (data->player_angle >= 2 * PI)
		data->player_angle -= 2 * PI;
}

static void	wasd(t_data *data, t_fpos *new_pos, double range)
{
	if (data->key[w])
		angled_moving(new_pos, range, data->player_angle);
	if (data->key[s])
		angled_moving(new_pos, range, data->player_angle + PI);
	if (data->key[a])
		angled_moving(new_pos, range, data->player_angle + PI / 2);
	if (data->key[d])
		angled_moving(new_pos, range, data->player_angle - PI / 2);
}

static double	get_move_range(t_data *data)
{
	double	range;

	if (data->key[shift] && data->stamina > 1 && !data->is_exhausted
		&& (data->key[w] || data->key[a] || data->key[s] || data->key[d]))
	{
		range = MOVE_CONST * 2;
		data->stamina -= 2;
		if (data->stamina == 0)
			data->is_exhausted = true;
	}
	else
	{
		range = MOVE_CONST;
		if (data->stamina < 100)
			data->stamina++;
		if (data->stamina == 100)
			data->is_exhausted = false;
	}
	return (range);
}

void	move(t_data *data)
{
	t_fpos	new_pos;

	new_pos = data->player_pos;
	wasd(data, &new_pos, get_move_range(data));
	arrows(data);
	data->interaction = data->key[e];
	if (!is_collision(data->env_map, new_pos.x, new_pos.y))
		data->player_pos = new_pos;
	else if (!is_collision(data->env_map, new_pos.x, data->player_pos.y))
		data->player_pos.x = new_pos.x;
	else if (!is_collision(data->env_map, data->player_pos.x, new_pos.y))
		data->player_pos.y = new_pos.y;
	if (data->env_map[(int)data->player_pos.y][(int)data->player_pos.x].type
		== e_key)
	{
		data->env_map[(int)data->player_pos.y][(int)data->player_pos.x].type
			= e_empty;
		data->key_left--;
		if (data->key_left == 0)
			game_over(data, true);
	}
}
