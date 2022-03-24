/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:35:38 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 19:17:23 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *strin, int char_search)
{
	if (char_search > 127)
	{
		char_search %= 256;
	}
	while (*strin)
	{
		if (*strin == char_search)
		{
			return ((char *)strin);
		}
		strin++;
	}
	if (*strin == char_search)
	{
		return ((char *)strin);
	}
	return (NULL);
}
