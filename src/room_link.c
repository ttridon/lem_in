/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 14:59:36 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/05 18:49:34 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	alloc_direction(t_lab *lab, t_link *link)
{
	int		i;
	int		n;
	t_link	*tmp;

	while (lab)
	{
		n = 0;
		tmp = link;
		while (tmp)
		{
			if (ft_strequ(lab->room->name, tmp->link_1)
					|| ft_strequ(lab->room->name, tmp->link_2))
				n++;
			tmp = tmp->next;
		}
		lab->room->direction = (t_room **)malloc(sizeof(t_room *) * (n + 1));
		i = 0;
		while (i < n)
		{
			lab->room->direction[i] = NULL;
			i++;
		}
		lab = lab->next;
	}
}

static void	set_direction(t_room *room_1, t_room *room_2)
{
	int		i;

	i = 0;
	while (room_1->direction[i])
		i++;
	room_1->direction[i] = room_2;
	i = 0;
	while (room_2->direction[i])
		i++;
	room_2->direction[i] = room_1;
}

void		set_link(t_lab *lab, t_link *link)
{
	t_room	*room_1;
	t_room	*room_2;
	t_lab	*tmp;

	alloc_direction(lab, link);
	tmp = lab;
	while (link)
	{
		lab = tmp;
		while (!ft_strequ(link->link_1, lab->room->name))
			lab = lab->next;
		room_1 = lab->room;
		lab = tmp;
		while (!ft_strequ(link->link_2, lab->room->name))
			lab = lab->next;
		room_2 = lab->room;
		set_direction(room_1, room_2);
		link = link->next;
	}
}
