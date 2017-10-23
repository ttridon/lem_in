/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 13:42:59 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 18:04:51 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		final_step(t_data *data, t_lab *lab, t_input *input)
{
	t_path	*path;

	path = NULL;
	direct_link(data, &path);
	while (ft_ispath(data, path))
	{
		if (!algo(data->end, data, lab, path))
			break ;
		save_path(&path, data->start);
		set_algo(lab, data, path);
	}
	if (path)
	{
		read_and_free_input(input);
		display_ant(path, data);
	}
	else
		ft_putendl("Error");
}

void		set_algo(t_lab *lab, t_data *data, t_path *path)
{
	t_room	*tmp;

	while (lab)
	{
		lab->room->passage = 0;
		lab->room->poids = INT_MAX;
		lab = lab->next;
	}
	data->end->poids = 0;
	while (path)
	{
		tmp = path->step;
		while (tmp)
		{
			tmp->passage = 1;
			tmp = tmp->next;
		}
		path = path->next;
	}
}

static void	set_room(t_room **room, t_lab *lab)
{
	int		p;

	p = INT_MAX;
	while (lab)
	{
		if (p > lab->room->poids && !lab->room->passage)
		{
			p = lab->room->poids;
			*room = lab->room;
		}
		lab = lab->next;
	}
}

int			algo(t_room *room, t_data *data, t_lab *lab, t_path *path)
{
	int		i;
	t_room	*tmp;

	i = 0;
	room->passage = 1;
	while (room->direction[i])
	{
		if (room->direction[i] == data->start)
		{
			data->start->next = room;
			return (1);
		}
		if (!room->direction[i]->passage)
		{
			room->direction[i]->poids = room->poids + 1;
			room->direction[i]->next = room;
		}
		i++;
	}
	tmp = room;
	set_room(&room, lab);
	if (room == tmp || !algo(room, data, lab, path))
		return (0);
	return (1);
}
