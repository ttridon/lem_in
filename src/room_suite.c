/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_suite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:56:18 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 17:07:11 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*find_ptr(t_lab *lab, char *line)
{
	while (lab)
	{
		if (ft_strnequ(lab->room->name, line, ft_strchr(line, ' ') - line))
			return (lab->room);
		lab = lab->next;
	}
	return (NULL);
}

static void		norme(t_lab **lab, t_data *data, char *line, int type)
{
	creat_room(lab, line);
	if (type == 1)
		data->start = find_ptr(*lab, line);
	else
		data->end = find_ptr(*lab, line);
}

int				set_start_end(char **line, t_data *data, t_lab **lab)
{
	int type;

	if (!line)
		return (0);
	type = !ft_strcmp(*line, "##start") ? 1 : 0;
	if ((type && data->start) || (!type && data->end))
		return (0);
	add_to_input(data, line);
	if (get_next_line(0, line) > 0)
	{
		if (!check_if_valid_room(*line, *lab))
		{
			ft_strdel(line);
			return (0);
		}
		else
			norme(lab, data, *line, type);
	}
	else
		return (0);
	return (1);
}
