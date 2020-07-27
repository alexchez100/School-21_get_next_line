/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsansa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:14:01 by gsansa            #+#    #+#             */
/*   Updated: 2020/07/14 12:16:11 by gsansa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_free_mod(char **s)
{
	free(*s);
	return (-1);
}

static int		ft_strjoin_mod(char **ost, char **buf)
{
	char		*vrem;

	if ((vrem = ft_strjoin(*ost, *buf)))
	{
		free(*ost);
		*ost = vrem;
		return (1);
	}
	free(*ost);
	free(*buf);
	return (-1);
}

static int		ft_search_n(char **ost, char **line)
{
	char		*pointer_n;
	char		*vrem;

	(*ost != NULL) ? (pointer_n = ft_strchr(*ost, '\n')) :
			(pointer_n = NULL);
	if (pointer_n)
	{
		*pointer_n = '\0';
		free(*line);
		if (!(*line = ft_strdup(*ost)))
			return (ft_free_mod(ost));
		if (!(vrem = ft_strdup(++pointer_n)))
		{
			free(*line);
			return (ft_free_mod(ost));
		}
		free(*ost);
		(ft_strlen(vrem) > 0) ? (*ost = vrem) :
				(*ost = NULL);
		if (!(ft_strlen(vrem) > 0))
			free(vrem);
		return (1);
	}
	return (0);
}

static int		ft_return(char **ost, char **line)
{
	int			res;

	res = ft_search_n(ost, line);
	if (res == 1)
		return (1);
	if (res == -1)
		return (ft_free_mod(ost));
	if (ft_strlen(*ost))
	{
		free(*line);
		if (!(*line = ft_strdup(*ost)))
			return (ft_free_mod(ost));
		free(*ost);
		*ost = NULL;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	int			rd;
	static char *ost[1024];
	int			res;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024 || !line ||
		!(buf = (char*)malloc(BUFFER_SIZE + 1)) ||
		!(*line = ft_strdup("")))
		return (-1);
	while ((rd = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd] = '\0';
		if (ft_strjoin_mod(&ost[fd], &buf) == -1)
			return (-1);
		if ((res = ft_search_n(&ost[fd], line)) != 0)
		{
			free(buf);
			return (res);
		}
	}
	free(buf);
	if (rd < 0)
		return (ft_free_mod(line));
	return (ft_return(&ost[fd], line));
}
