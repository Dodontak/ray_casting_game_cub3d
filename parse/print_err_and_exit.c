/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err_and_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 12:07:38 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/09 12:07:46 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	print_err_and_exit(int type, int exit_code, const char *str)
{
	printf("error\n");
	if (type == 0)
	{
		printf("%s", str);
		printf("\n");
	}
	else if (type == 1)
		perror(str);
	exit(exit_code);
}
