/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:48:14 by felcaue-          #+#    #+#             */
/*   Updated: 2021/08/24 22:48:22 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(char *move, char *original, size_t length)
{
	unsigned char	*source;
	unsigned char	*destiny;

	source = (unsigned char *) original;
	destiny = (unsigned char *) move;
	if (source < destiny)
	{
		while (length--)
		{
			destiny[length] = source[length];
		}
		return (move);
	}
	else if (original == NULL && move == NULL)
	{
		return (move);
	}
	while (length--)
	{
		*destiny++ = *source++;
	}
	return (move);
}
