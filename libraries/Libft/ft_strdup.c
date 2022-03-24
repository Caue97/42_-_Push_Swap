/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:38:41 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/04 18:43:54 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *strin_g)
{
	size_t	length;
	char	*new_cpy;

	length = ft_strlen(strin_g) + 1;
	new_cpy = malloc(length);
	if (!new_cpy)
	{
		return (0);
	}
	return (ft_memcpy(new_cpy, strin_g, length));
}
