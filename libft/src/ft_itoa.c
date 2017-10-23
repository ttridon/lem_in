/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 14:14:24 by ttridon           #+#    #+#             */
/*   Updated: 2016/02/22 15:22:45 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	int		nb;
	int		len;

	len = n < 0 ? 2 : 1;
	nb = n;
	while ((nb >= 10 || nb <= -10) && len++)
		nb = nb / 10;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n < 0 && len--)
	{
		s[0] = '-';
		s[len] = 48 - n % 10;
		n = n / (-10);
	}
	while (--len >= 0 && s[len] != '-')
	{
		s[len] = n % 10 + 48;
		n = n / 10;
	}
	return (s);
}
