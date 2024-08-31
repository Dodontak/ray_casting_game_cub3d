/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonlim <seonlim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 11:42:43 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/24 15:01:30 by seonlim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_data	data;

	init_data(&data, ac, av);
	set_sprites(&data);
	data.frame = 0;
	mlx_hook(data.win, EXIT_CLICK, 0, exit_cub3d, &data);
	mlx_hook(data.win, KEY_PRESS, 0, key_press, &data);
	mlx_hook(data.win, KEY_RELEASE, 0, key_release, &data);
	mlx_hook(data.win, MOUSE_MOVE, 0, mouse_hook, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
}
