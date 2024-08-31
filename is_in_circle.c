/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_circle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:08:23 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/16 21:10:14 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

bool	is_in_circle(t_ipos *point, int center_x, int center_y, int r)
{
	if (pow(center_x - point->x, 2) + pow(center_y - point->y, 2) <= pow(r, 2))
		return (true);
	return (false);
}
