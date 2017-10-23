/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:25:15 by ttridon           #+#    #+#             */
/*   Updated: 2016/06/06 17:12:12 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **s)
{
	if (*s)
	{
		ft_bzero(*s, ft_strlen(*s));
		free(*s);
		*s = NULL;
	}
}