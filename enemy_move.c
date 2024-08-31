/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:38:30 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 14:35:01 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

static void	get_new_pos(t_fpos *new, t_pq_direction dir, double range)
{
	if (dir == p_north)
		angled_moving(new, range, 2 * PI / 4);
	else if (dir == p_north_west)
		angled_moving(new, range, 3 * PI / 4);
	else if (dir == p_west)
		angled_moving(new, range, 4 * PI / 4);
	else if (dir == p_west_south)
		angled_moving(new, range, 5 * PI / 4);
	else if (dir == p_south)
		angled_moving(new, range, 6 * PI / 4);
	else if (dir == p_south_east)
		angled_moving(new, range, 7 * PI / 4);
	else if (dir == p_east)
		angled_moving(new, range, 8 * PI / 4);
	else if (dir == p_east_north)
		angled_moving(new, range, PI / 4);
}

static bool	is_invalid_path(t_data *data, t_pq *pq, t_fpos *pos)
{
	const t_ipos	map_pos = {(int)pos->x, (int)pos->y};

	if (map_pos.x < 0 || map_pos.x >= data->map.map_x_len)
		return (true);
	if (map_pos.y < 0 || map_pos.y >= data->map.map_y_len)
		return (true);
	if (data->env_map[map_pos.y][map_pos.x].type == e_wall)
		return (true);
	if (pq->visit[map_pos.y][map_pos.x])
		return (true);
	return (false);
}

static void	push_all_directions(t_data *data, t_pq *pq, t_pq_node *cur)
{
	t_pq_node	*new;
	t_fpos		tmp;
	int			i;

	i = -1;
	while (++i < p_zero)
	{
		tmp = cur->pos;
		get_new_pos(&tmp, i, 1);
		if (is_invalid_path(data, pq, &tmp))
			continue ;
		pq->visit[(int)tmp.y][(int)tmp.x] = true;
		new = (t_pq_node *)safe_malloc(sizeof(t_pq_node));
		if (cur->dir == p_zero)
			new->dir = i;
		else
			new->dir = cur->dir;
		new->dist = cur->dist + ENEMY_MOVE;
		new->pos = tmp;
		new->score = new->dist
			+ get_euclidian_dist(&new->pos, &data->player_pos);
		pq_push(pq, new);
	}
}

static t_pq_direction	get_enemy_direction(t_data *data)
{
	t_pq			pq;
	t_pq_node		*cur;
	t_pq_direction	ret;

	ret = p_zero;
	pq_init(data, &pq);
	cur = pq_pop(&pq);
	push_all_directions(data, &pq, cur);
	while (pq.heap_size)
	{
		free(cur);
		cur = pq_pop(&pq);
		if ((int)cur->pos.x == (int)data->player_pos.x
			&& (int)cur->pos.y == (int)data->player_pos.y)
		{
			ret = cur->dir;
			break ;
		}
		push_all_directions(data, &pq, cur);
	}
	free(cur);
	pq_free(data, &pq);
	return (ret);
}

void	enemy_move(t_data *data)
{
	static t_fpos			d = {0, 0};
	t_fpos					new_pos;
	t_pq_direction			enemy_dir;
	bool					door_collision;

	if (!data->enemy_frame)
	{
		enemy_dir = get_enemy_direction(data);
		new_pos = data->enemy_pos;
		get_new_pos(&new_pos, enemy_dir, ENEMY_MOVE);
		d.x = (new_pos.x - data->enemy_pos.x) / ENEMY_FRAME;
		d.y = (new_pos.y - data->enemy_pos.y) / ENEMY_FRAME;
	}
	if (data->enemy_frame < ENEMY_FRAME)
	{
		door_collision = enemy_change_door(data, &data->enemy_pos, &d);
		if (door_collision)
			return ;
		data->enemy_pos.x += d.x;
		data->enemy_pos.y += d.y;
		data->enemy_frame++;
	}
	else
		data->enemy_frame = 0;
}
