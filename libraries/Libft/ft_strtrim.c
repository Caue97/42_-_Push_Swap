/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:25:43 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/04 20:42:25 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	counter_01;
	size_t	counter_02;

	counter_01 = 0;
	if (!s1 || !set)
	{
		return (0);
	}
	while (s1[counter_01] != '\0' && ft_strchr(set, s1[counter_01]))
	{
		counter_01++;
	}
	counter_02 = ft_strlen(s1);
	while (counter_02 != 0 && ft_strchr(set, s1[counter_02]))
	{
		counter_02--;
	}
	if ((int)(counter_02 - counter_01 + 1) <= 0)
	{
		return (ft_calloc(1, 1));
	}
	return (ft_substr(s1, counter_01, (counter_02 - counter_01 + 1)));
}
