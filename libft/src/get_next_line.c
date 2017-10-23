/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 12:07:41 by ttridon           #+#    #+#             */
/*   Updated: 2016/05/02 17:37:57 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/get_next_line.h"
#include <unistd.h>

static	int		check_n(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

static	int		add_save(char **line, char *save)
{
	int		i;
	int		j;
	int		end;

	i = 0;
	j = 0;
	end = check_n(save);
	(*line) = ft_strnew((size_t)end);
	while (i < end)
	{
		(*line)[i] = save[i];
		i++;
	}
	if (save[i])
	{
		i++;
		while (save[i])
			save[j++] = save[i++];
		save[j] = '\0';
		return (1);
	}
	save[0] = '\0';
	return (0);
}

static	int		add_buf(char **line, char *buf, char *save)
{
	int		i;
	int		end;
	int		cond;
	char	*tmp;

	i = 0;
	cond = 0;
	end = check_n(buf);
	if ((size_t)end != ft_strlen(buf) && (cond = 1))
	{
		buf[end] = '\0';
		while (buf[++end])
			save[i++] = buf[end];
		save[i] = '\0';
	}
	if (!(*line))
		(*line) = ft_strnew((size_t)end);
	tmp = ft_strjoin(*line, buf);
	free(*line);
	*line = tmp;
	if (cond == 0)
		return (0);
	return (1);
}

static int		set_line(int const fd, char **line, char *save)
{
	char		buf[BUFF_SIZE + 1];
	long long	ret;

	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		if (*line != NULL && ft_strlen(*line) > 0)
			return (1);
		else
			return (0);
	}
	buf[ret] = '\0';
	if (add_buf(line, buf, save) != 1)
		set_line(fd, line, save);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static char	save[256][BUFF_SIZE];

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (save[0] != '\0')
		if (add_save(line, save[fd]))
			return (1);
	return (set_line(fd, line, save[fd]));
}
