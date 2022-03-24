/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:47:52 by felcaue-          #+#    #+#             */
/*   Updated: 2021/08/24 21:47:16 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(char *copy, const void *original, size_t length)
{
	unsigned char	*source;
	unsigned char	*destiny;

	if (original == NULL && copy == NULL)
	{
		return (copy);
	}
	destiny = (unsigned char *) copy;
	source = (unsigned char *) original;
	while (length--)
	{
		*destiny++ = *source++;
	}
	return (copy);
}
