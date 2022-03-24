/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:49:27 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 19:21:37 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(int number_o, int f_negative_o);

int	ft_atoi(const char *to_convert)
{
	int	f_negative;
	int	number;
	int	what_return;

	number = 0;
	f_negative = 0;
	while ((*to_convert >= 9 && *to_convert <= 13) || *to_convert == 32)
		to_convert++;
	if (*to_convert == '-' || *to_convert == '+')
	{
		if (*to_convert == '-')
			f_negative = 1;
		to_convert++;
	}
	while (*to_convert >= '0' && *to_convert <= '9')
	{
		number = number * 10 + (*to_convert - '0');
		to_convert++;
	}
	what_return = check_overflow(number, f_negative);
	if (what_return != 1)
		return (what_return);
	if (f_negative)
		return (number *= -1);
	return (number);
}

static int	check_overflow(int number_o, int f_negative_o)
{
	unsigned int	num_for_check;

	num_for_check = number_o;
	if (num_for_check > 2147483648 && f_negative_o)
	{
		return (0);
	}
	if (num_for_check > 2147483647 && !f_negative_o)
	{
		return (-1);
	}
	return (1);
}
