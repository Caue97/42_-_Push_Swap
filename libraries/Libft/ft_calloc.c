/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 17:58:31 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/04 18:07:32 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n_locate, size_t n_array_size)
{
	size_t	*position;
	size_t	total_size;
	int		fill;

	total_size = n_locate * n_array_size;
	fill = 0;
	position = malloc(total_size);
	if (!position || (total_size > INT_MAX))
	{
		return (NULL);
	}
	ft_memset(position, fill, total_size);
	return ((void *) position);
}
