/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:24:14 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/12 16:33:21 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_base(int n, int base)
{
	char	*s;
	int		nb;
	int		len;

	len = 1;
	nb = n;
	while (nb >= base)
	{
		nb = nb / base;
		len++;
	}
	if (base == 10)
		return (ft_itoa(n));
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	while (--len >= 0)
	{
		s[len] = n % base > 9 ? n % base - 10 + 'a' : n % base + 48;
		n = n / base;
	}
	return (s);
}
