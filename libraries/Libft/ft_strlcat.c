/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:48:28 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 21:48:06 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *contat, const char *original, size_t size)
{
	size_t	counter_1;
	size_t	counter_2;

	if (size <= ft_strlen(contat))
	{
		return (size + ft_strlen(original));
	}
	counter_1 = ft_strlen(contat);
	counter_2 = 0;
	while ((original[counter_2] != '\0') && ((counter_1 + 1) < size))
	{
		contat[counter_1] = original[counter_2];
		counter_1++;
		counter_2++;
	}
	contat[counter_1] = '\0';
	return (ft_strlen(contat) + ft_strlen(&original[counter_2]));
}
