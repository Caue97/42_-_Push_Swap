/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:48:20 by felcaue-          #+#    #+#             */
/*   Updated: 2021/08/24 22:10:56 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *strin, int search)
{
	const char	*strin_end;

	if (search > 127)
	{
		search %= 256;
	}
	strin_end = strin;
	while (*strin_end)
	{
		strin_end++;
	}
	while (strin_end != strin)
	{
		if (*strin_end == search)
		{
			return ((char *) strin_end);
		}
		strin_end--;
	}
	if (*strin_end == search)
	{
		return ((char *)strin_end);
	}
	return (NULL);
}
