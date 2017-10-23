/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:17:38 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 18:04:36 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void		pas_beau(t_data *data)
{
	int		i;
	int		j;
	t_room	**direction;

	i = 0;
	while (data->end->direction[i])
		i++;
	direction = (t_room **)malloc(sizeof(t_room *) * i);
	i = 0;
	j = 0;
	while (data->end->direction[i])
	{
		if (data->end->direction[i] != data->start)
		{
			direction[j] = data->end->direction[i];
			j++;
		}
		i++;
	}
	direction[j] = NULL;
	free(data->end->direction);
	data->end->direction = direction;
}

int			ft_ispath(t_data *data, t_path *path)
{
	int	i;

	i = 0;
	if (path)
		;
	while (data->end->direction[i])
	{
		if (data->end->direction[i]->passage == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	parser_ant_number(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	if (!(get_next_line(0, &line) > 0))
		return (0);
	else
	{
		if (!ft_isdigit(line[i]))
			return (0);
		while (line[i])
		{
			if (!ft_isdigit(line[i]))
			{
				ft_strdel(&line);
				return (0);
			}
			i++;
		}
		data->input->line = ft_strdup(line);
		data->ant = ft_atoi(line);
		ft_strdel(&line);
	}
	return (1);
}

void		direct_link(t_data *data, t_path **path)
{
	int	i;

	i = 0;
	while (data->end->direction[i])
	{
		if (data->end->direction[i] == data->start)
		{
			data->start->next = data->end;
			save_path(path, data->start);
			pas_beau(data);
		}
		i++;
	}
}

int			main(void)
{
	t_data	*data;
	t_lab	*lab;
	t_input	*input;

	lab = NULL;
	data = (t_data *)malloc(sizeof(t_data));
	input = (t_input *)malloc(sizeof(t_input));
	data->start = NULL;
	data->end = NULL;
	data->input = input;
	input->next = NULL;
	if (!parser_ant_number(data))
	{
		ft_putendl("Error");
		return (0);
	}
	else if (!parser_link(parser_room(data, &lab), lab, data))
	{
		ft_putendl("Error");
		return (0);
	}
	final_step(data, lab, input);
	return (0);
}
