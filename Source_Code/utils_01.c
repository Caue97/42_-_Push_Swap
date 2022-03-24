/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:05:28 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:51:14 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	atoi_safe(t_content *content, char **argv, t_info *inf, int i)
{
	int					signal;
	unsigned long int	number;
	const char			*nptr;

	number = 0;
	signal = 1;
	nptr = argv[i];
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
			signal *= -1;
		if (!ft_isdigit(*nptr))
			validation_error(content, inf, argv, i);
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number = (*nptr - 48) + (number * 10);
		nptr++;
	}
	if ((number > MAX_INT && signal > 0) || (signal < 0 && number > -MIN_INT)
		|| (*nptr && *nptr != ' '))
		validation_error(content, inf, argv, i);
	return (signal * number);
}

int	max(int nb_1, int nb_2)
{
	if (nb_1 > nb_2)
		return (nb_1);
	return (nb_2);
}

int	min(int nb_1, int nb_2)
{
	if (nb_1 < nb_2)
		return (nb_1);
	return (nb_2);
}

int	abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
