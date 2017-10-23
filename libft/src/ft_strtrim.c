/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 15:02:08 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 15:07:36 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s_cpy;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (s[start] && ft_isspace(s[start]))
		start++;
	if (start != end)
		while (s[end - 1] && ft_isspace(s[end - 1]))
			end--;
	s_cpy = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s_cpy)
		return (NULL);
	while (start != end)
		s_cpy[i++] = s[start++];
	s_cpy[i] = '\0';
	return (s_cpy);
}
