/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 13:56:56 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 11:06:14 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void		add_link(char *line, t_link **link)
{
	t_link	*new_link;
	t_link	*tmp;

	tmp = *link;
	new_link = (t_link *)malloc(sizeof(t_link));
	new_link->link_1 = ft_strndup(line, ft_strchr(line, '-') - line);
	new_link->link_2 = ft_strdup(&line[ft_strchr(line, '-') - line + 1]);
	new_link->next = NULL;
	if (!tmp)
		*link = new_link;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_link;
	}
}

void		add_to_input(t_data *data, char **line)
{
	t_input *new_input;

	new_input = (t_input *)malloc(sizeof(t_input));
	new_input->next = NULL;
	new_input->line = ft_strdup(*line);
	while (data->input->next)
		data->input = data->input->next;
	data->input->next = new_input;
	ft_strdel(line);
}

void		read_and_free_input(t_input *input)
{
	t_input	*tmp;

	while (input)
	{
		ft_putendl(input->line);
		tmp = input;
		input = input->next;
		ft_strdel(&(tmp->line));
		free(tmp);
	}
}

static void	save_coordonate(char *line, t_room *new_room)
{
	new_room->x = ft_atoi(line);
	new_room->y = ft_atoi(&line[ft_strchr(line, ' ') - line]);
}

void		creat_room(t_lab **lab, char *line)
{
	t_lab	*new_lab;
	t_lab	*tmp;
	t_room	*new_room;

	new_lab = (t_lab *)malloc(sizeof(t_lab));
	new_lab->next = NULL;
	if (*lab == NULL)
		*lab = new_lab;
	else
	{
		tmp = *lab;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new_lab;
	}
	new_room = (t_room *)malloc(sizeof(t_room));
	new_lab->room = new_room;
	new_room->name = ft_strndup(line, ft_strchr(line, ' ') - line);
	save_coordonate(&line[ft_strchr(line, ' ') - line + 1], new_room);
	new_room->poids = INT_MAX;
	new_room->passage = 0;
	new_room->direction = NULL;
	new_room->next = NULL;
}
