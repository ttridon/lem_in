/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 11:35:56 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 16:16:09 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	set_path(t_path *path)
{
	t_room	*tmp;

	while (path)
	{
		tmp = path->step;
		while (tmp)
		{
			tmp->passage = 0;
			tmp = tmp->next;
		}
		path = path->next;
	}
}

static int	ft_isant(t_path *path)
{
	t_room	*tmp;

	while (path)
	{
		tmp = path->step;
		while (tmp)
		{
			if (tmp->passage)
				return (1);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (0);
}

static void	ant_to_next_room(t_room *room, t_data *data)
{
	if (room->next)
		ant_to_next_room(room->next, data);
	if (room->passage)
	{
		if (room->next)
		{
			room->passage = 0;
			if (room->next != data->end)
			{
				room->next->passage = 1;
				room->next->poids = room->poids;
			}
			ft_putstr("L");
			ft_putnbr(room->poids);
			ft_putstr("-");
			ft_putstr(room->next->name);
			ft_putstr(" ");
		}
	}
}

static void	ant_to_start(t_room *room, t_data *data)
{
	static int ant_number = 1;

	room->poids = ant_number;
	if (room != data->end)
		room->passage = 1;
	ant_number++;
	ft_putstr("L");
	ft_putnbr(room->poids);
	ft_putstr("-");
	ft_putstr(room->name);
	ft_putstr(" ");
}

void		display_ant(t_path *path, t_data *data)
{
	t_path	*tmp;

	set_path(path);
	while (data->ant || ft_isant(path))
	{
		ft_putstr("\n");
		tmp = path;
		while (tmp)
		{
			ant_to_next_room(tmp->step, data);
			if (data->ant >= tmp->length)
			{
				ant_to_start(tmp->step, data);
				data->ant--;
			}
			else if (data->ant && !path->step->passage)
			{
				ant_to_start(path->step, data);
				data->ant--;
			}
			tmp = tmp->next;
		}
	}
	ft_putstr("\n");
}
