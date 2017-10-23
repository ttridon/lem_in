/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 15:10:15 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 16:18:10 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		while (s1[i + k] == s2[k])
		{
			k++;
			if (s2[k] == '\0')
				return ((char*)&s1[i]);
		}
		k = 0;
		i++;
	}
	return (NULL);
}
