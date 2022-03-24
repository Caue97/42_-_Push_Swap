/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:31:38 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 18:05:04 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *bf_01, const void *bf_02, size_t c_size)
{
	unsigned char	*first;
	unsigned char	*second;
	size_t			counter;

	first = (unsigned char *)bf_01;
	second = (unsigned char *)bf_02;
	counter = 0;
	while (counter < c_size)
	{
		if (first[counter] != second[counter])
		{
			return ((int)(first[counter] - second[counter]));
		}
		if (c_size == 0)
		{
			return ((int)c_size);
		}
		counter++;
	}
	return (0);
}
