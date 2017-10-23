/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 18:50:03 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 17:49:34 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <stdio.h>

static int	check_link(char *line)
{
	int	i;

	i = 0;
	if (line[i] == 'L')
		return (0);
	while (line[i] && line[i] != '-')
	{
		if (!ft_isalnum(line[i]))
			return (0);
		i++;
	}
	if (!line[i] || line[i] != '-')
		return (0);
	while (line[++i])
		if (!ft_isalnum(line[i]))
			return (0);
	return (1);
}

static int	check_if_valid_link(char *line, t_lab *lab)
{
	int	n;
	int	valid;

	n = ft_strchr(line, '-') - line;
	if (ft_strnequ(line, &line[n + 1], ft_strlen(lab->room->name))
			&& ft_strnequ(line, &line[n + 1], n))
		return (0);
	valid = 0;
	while (lab)
	{
		if (ft_strnequ(line, lab->room->name, ft_strlen(lab->room->name))
			&& ft_strnequ(line, lab->room->name, n))
			valid++;
		if (!ft_strncmp(&line[n + 1], lab->room->name,
					ft_strlen(lab->room->name))
				&& !ft_strncmp(&line[n + 1], lab->room->name,
					ft_strlen(&line[n + 1])))
			valid++;
		lab = lab->next;
	}
	if (valid != 2)
		return (0);
	return (1);
}

static int	norme(t_lab *lab, t_link **link, t_data *data)
{
	char *line;

	while (get_next_line(0, &line) > 0)
	{
		if (line[0] != '#')
		{
			if (!check_link(line) || !check_if_valid_link(line, lab))
			{
				set_link(lab, *link);
				ft_strdel(&line);
				return (1);
			}
			add_link(line, link);
		}
		if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
		{
			set_link(lab, *link);
			ft_strdel(&line);
			return (1);
		}
		add_to_input(data, &line);
	}
	return (0);
}

int			parser_link(char *line, t_lab *lab, t_data *data)
{
	t_link	*link;

	link = NULL;
	if (!line || !check_link(line) || !check_if_valid_link(line, lab))
		return (0);
	add_link(line, &link);
	add_to_input(data, &line);
	if (norme(lab, &link, data))
		return (1);
	set_link(lab, link);
	return (1);
}
