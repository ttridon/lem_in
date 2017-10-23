/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:13:54 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 18:04:30 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# define INT_MAX 2147483647

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				poids;
	int				passage;
	struct s_room	*next;
	struct s_room	**direction;
}					t_room;

typedef struct		s_lab
{
	t_room			*room;
	struct s_lab	*next;
}					t_lab;

typedef struct		s_input
{
	char			*line;
	struct s_input	*next;
}					t_input;

typedef struct		s_data
{
	t_room			*start;
	t_room			*end;
	int				ant;
	t_input			*input;
}					t_data;

typedef struct		s_link
{
	char			*link_1;
	char			*link_2;
	struct s_link	*next;
}					t_link;

typedef struct		s_path
{
	int				length;
	struct s_room	*step;
	struct s_path	*next;
}					t_path;

void				add_to_input(t_data *data, char **line);
void				add_link(char *line, t_link **link);
void				read_and_free_input(t_input *input);
void				creat_room(t_lab **lab, char *line);
void				set_link(t_lab *lab, t_link *link);
void				save_path(t_path **path, t_room *room);
void				set_algo(t_lab *lab, t_data *data, t_path *path);
void				display_ant(t_path *path, t_data *data);
void				final_step(t_data *data, t_lab *lab, t_input *input);
void				direct_link(t_data *data, t_path **path);
void				pas_beau(t_data *data);
char				*parser_room(t_data *data, t_lab **lab);
int					parser_link(char *line, t_lab *lab, t_data *data);
int					algo(t_room *room, t_data *data, t_lab *lab, t_path *path);
int					ft_ispath(t_data *data, t_path *path);
int					set_start_end(char **line, t_data *data, t_lab **lab);
int					check_if_valid_room(char *line, t_lab *lab);

#endif
