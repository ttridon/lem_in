/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 13:52:28 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 17:07:45 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	save_path(t_path **path, t_room *start)
{
	t_path	*tmp;
	t_path	*new_path;

	new_path = (t_path *)malloc(sizeof(t_path));
	new_path->length = 0;
	new_path->next = NULL;
	new_path->step = start->next;
	while (start)
	{
		new_path->length++;
		start = start->next;
	}
	if (!(*path))
		*path = new_path;
	else
	{
		tmp = *path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_path;
	}
}
