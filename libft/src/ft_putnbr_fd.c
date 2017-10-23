/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/13 16:30:37 by ttridon           #+#    #+#             */
/*   Updated: 2016/03/13 16:31:34 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n < (-10))
			ft_putnbr_fd(n / (-10), fd);
	}
	else if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n >= 0)
		ft_putchar_fd(n % 10 + 48, fd);
	else
		ft_putchar_fd(48 - n % 10, fd);
}
