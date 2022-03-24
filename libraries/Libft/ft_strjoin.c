/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:25:43 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 20:41:31 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strng_u;
	char	*destiny_ret;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	strng_u = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)
				+ 1) * sizeof(char));
	if (strng_u == NULL)
	{
		return (NULL);
	}
	destiny_ret = strng_u;
	while (*s1)
	{
		*strng_u++ = *s1++;
	}
	while (*s2)
	{
		*strng_u++ = *s2++;
	}
	*strng_u = '\0';
	return (destiny_ret);
}
