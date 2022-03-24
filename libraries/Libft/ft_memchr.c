/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:23:11 by felcaue-          #+#    #+#             */
/*   Updated: 2021/08/24 22:43:54 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *where_s, int what_s, size_t length_s)
{
	unsigned char	*compare;

	while (length_s-- > 0)
	{
		compare = (unsigned char *) where_s;
		if (*compare == (unsigned char) what_s)
		{
			return (compare);
		}
		where_s++;
	}
	return (NULL);
}
