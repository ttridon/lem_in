/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 15:17:58 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 15:19:55 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*l;

	i = 0;
	l = NULL;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			l = (char*)&s[i];
		i++;
	}
	if (c == '\0')
		return ((char*)&s[i]);
	return (l);
}
