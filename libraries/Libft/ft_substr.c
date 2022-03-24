/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:25:43 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/04 20:46:38 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_strng;
	size_t	size_og;

	size_og = ft_strlen(s);
	if (!s)
	{
		return (0);
	}
	if (start > size_og)
	{
		return (ft_strdup(""));
	}
	sub_strng = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub_strng)
	{
		return (0);
	}
	ft_strlcpy(sub_strng, (s + start), len + 1);
	sub_strng[len] = '\0';
	return (sub_strng);
}
