/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:24:25 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/04 19:34:46 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num_hold;

	num_hold = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num_hold = -n;
	}
	if (num_hold > 9)
	{
		ft_putnbr_fd(num_hold / 10, fd);
		ft_putnbr_fd(num_hold % 10, fd);
	}
	else
	{
		ft_putchar_fd(num_hold + '0', fd);
	}
}
