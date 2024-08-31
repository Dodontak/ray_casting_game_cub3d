/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_stamina_bar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:06:30 by seonlim           #+#    #+#             */
/*   Updated: 2023/07/24 14:16:11 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_stamina_bar(t_data *data)
{
	const t_ipos	st = {WIDTH / 2 - 400, HEIGHT * 0.1};
	const t_ipos	ed = {st.x + 800, st.y + 30};
	const t_ipos	in_st = {st.x + 5 + data->stamina * 800 / 100, st.y + 5};
	const t_ipos	in_ed = {ed.x - 5, ed.y - 5};

	draw_square(&data->img, &st, &ed, GREEN);
	draw_square(&data->img, &in_st, &in_ed, WHITE);
}
