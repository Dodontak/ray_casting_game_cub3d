/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byejeon <byejeon@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:44:12 by byejeon           #+#    #+#             */
/*   Updated: 2023/04/23 13:42:42 by byejeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	backup[BUFFER_SIZE + 1];
	char		*out;
	size_t		size;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (0);
	if (backup[0] != '\0' && ft_strchr(backup, '\n'))
	{
		size = find_nl_idx(backup) + 1;
		out = malloc(sizeof(char) * (size + 1));
		if (out == 0)
			return (0);
		ft_strlcpy(out, backup, size + 1);
		change_backup(backup, backup);
		return (out);
	}
	out = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (out == 0)
		return (0);
	ft_strlcpy(out, backup, BUFFER_SIZE + 1);
	out = make_line(out, backup, fd);
	return (out);
}

size_t	find_nl_idx(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

char	*make_line(char *out, char *backup, int fd)
{
	char	*buff;
	ssize_t	rd;

	while (1)
	{
		buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buff == 0)
			return (free_str(out, NULL));
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			backup[0] = '\0';
			return (free_str(out, buff));
		}
		buff[rd] = '\0';
		if (rd == 0 || ft_strchr(buff, '\n'))
			break ;
		out = join(out, buff);
		if (out == 0)
			return (0);
	}
	change_backup(backup, buff);
	out = join(out, buff);
	return (out);
}

char	*free_str(char *s1, char *s2)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (0);
}

void	change_backup(char *backup, char *str)
{
	char	*nlptr;
	size_t	i;

	i = 0;
	nlptr = ft_strchr(str, '\n');
	if (nlptr)
	{
		nlptr++;
		while (*nlptr)
			backup[i++] = *(nlptr++);
		backup[i] = '\0';
		return ;
	}
	while (*str)
		backup[i++] = *(str++);
	backup[i] = '\0';
	return ;
}
/*
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	fd = open("test", O_RDONLY);

	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}
*/
