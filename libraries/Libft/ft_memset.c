/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:48:02 by felcaue-          #+#    #+#             */
/*   Updated: 2021/08/24 22:27:17 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memory, int value, size_t length)
{
	char	*help;

	help = (char *) memory;
	while (length--)
	{
		*help++ = (char) value;
	}
	return (memory);
}
