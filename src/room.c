/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:35:42 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/07 13:07:10 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_room(char *line)
{
	int	i;
	int	space1;
	int	space2;

	i = 0;
	if (line[i] == 'L' || !ft_strchr(line, ' '))
		return (0);
	if ((space1 = ft_strchr(line, ' ') - line) <= 0)
		return (0);
	space2 = ft_strchr(&line[space1 + 1], ' ') - line;
	while (line[i] && i < space1)
		if (!ft_isprint(line[i++]))
			return (0);
	if (line[i++] != ' ')
		return (0);
	while (line[i] && i < space2)
		if (!ft_isdigit(line[i++]))
			return (0);
	if (line[i++] != ' ')
		return (0);
	while (line[i])
		if (!ft_isdigit(line[i++]))
			return (0);
	return (1);
}

int			check_if_valid_room(char *line, t_lab *lab)
{
	int	n;
	int	k;

	if (!check_room(line))
		return (0);
	n = ft_strchr(line, ' ') - line;
	while (lab)
	{
		if (!ft_strncmp(line, lab->room->name, ft_strlen(lab->room->name))
				&& !ft_strncmp(line, lab->room->name, n))
			return (0);
		if (lab->room->x == ft_atoi(&line[n + 1]))
		{
			k = ft_strchr(&line[n + 1], ' ') - line;
			if (lab->room->y == ft_atoi(&line[k + 1]))
				return (0);
		}
		lab = lab->next;
	}
	return (1);
}

static int	norme(char **line, t_lab **lab)
{
	if (!check_if_valid_room(*line, *lab))
	{
		ft_strdel(line);
		return (0);
	}
	else
		creat_room(lab, *line);
	return (1);
}

char		*parser_room(t_data *data, t_lab **lab)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#')
		{
			if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
				if (!set_start_end(&line, data, lab))
					return (NULL);
		}
		else if (ft_strchr(line, '-'))
			break ;
		else
		{
			if (!norme(&line, lab))
				return (0);
		}
		add_to_input(data, &line);
	}
	if (!data->start || !data->end)
		return (NULL);
	return (line);
}
