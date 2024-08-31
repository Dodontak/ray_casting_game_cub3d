/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rawdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:19:20 by byejeon           #+#    #+#             */
/*   Updated: 2023/07/13 13:22:33 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	nl_to_null(char *line);
static char	**add_a_line(char **rawdata, char *line);
static char	**when_first_add_line(char *line);

char	**make_rawdata(char **av)
{
	int		fd;
	char	**rawdata;
	char	*line;

	fd = open(av[1], O_RDONLY);
	rawdata = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		nl_to_null(line);
		rawdata = add_a_line(rawdata, line);
	}
	if (rawdata == NULL)
		print_err_and_exit(0, 1, "no contents in file\n");
	return (rawdata);
}

static void	nl_to_null(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = '\0';
		i++;
	}
}

static char	**add_a_line(char **rawdata, char *line)
{
	int		size;
	int		i;
	char	**newone;

	if (rawdata == NULL)
		return (when_first_add_line(line));
	size = 0;
	while (rawdata[size])
		size++;
	newone = malloc(sizeof(char *) * (size + 2));
	if (newone == 0)
		print_err_and_exit(1, 1, "parsing make rawdata");
	i = -1;
	while (++i < size)
		newone[i] = rawdata[i];
	newone[i++] = line;
	newone[i] = 0;
	free(rawdata);
	return (newone);
}

static char	**when_first_add_line(char *line)
{
	char	**newone;

	newone = malloc(sizeof(char *) * 2);
	if (newone == 0)
		print_err_and_exit(1, 1, "parsing make rawdata");
	newone[0] = line;
	newone[1] = 0;
	return (newone);
}
