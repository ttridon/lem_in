/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 19:01:11 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/12 21:27:18 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_bits(wint_t c)
{
	int	i;

	i = 1;
	while ((c = c >> 1))
		i++;
	return (i);
}

void	ft_putwchar(wint_t c)
{
	int	nbit;

	nbit = count_bits(c);
	if (nbit > 7)
	{
		if (nbit > 11)
		{
			if (nbit > 16)
			{
				ft_putchar(((c >> 17) & 0x7) | 0xf0);
				ft_putchar(((c >> 12) & 0x3f) | 0x80);
			}
			else
				ft_putchar(((c >> 12) & 0xf) | 0xe0);
			ft_putchar(((c >> 6) & 0x3f) | 0x80);
		}
		else
			ft_putchar(((c >> 6) & 0x1f) | 0xc0);
		ft_putchar((c & 0x3f) | 0x80);
	}
	else
		ft_putchar(c);
}
