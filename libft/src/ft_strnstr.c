/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 15:15:32 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 15:16:03 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i] && i < n)
	{
		while (s1[i + k] == s2[k] && (i + k) < n)
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
