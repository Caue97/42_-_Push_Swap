/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:48:32 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 21:39:51 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *copy, const char *original, size_t size)
{
	size_t	size_og;
	size_t	counter;

	size_og = ft_strlen(original);
	counter = 0;
	if (!original || !copy)
	{
		return (0);
	}
	if (size != 0)
	{
		while (original[counter] != '\0' && counter < (size - 1))
		{
			copy[counter] = original[counter];
			counter++;
		}
		copy[counter] = '\0';
	}
	return (size_og);
}
