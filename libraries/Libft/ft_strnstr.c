/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 20:36:44 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 20:24:59 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *l_txt, const char *see_th, size_t serc_len)
{
	size_t	counter_01;
	size_t	counter_02;
	size_t	this_lenght;

	counter_01 = 0;
	counter_02 = 0;
	this_lenght = ft_strlen(see_th);
	if (this_lenght == 0)
	{
		return ((char *)l_txt);
	}
	while (l_txt[counter_01] != '\0' && serc_len-- >= this_lenght)
	{
		if (l_txt[counter_01] == see_th[counter_02]
			&& ft_strncmp(((char *)l_txt + counter_01),
				see_th, this_lenght) == 0)
		{
			return ((char *)l_txt + counter_01);
		}
		counter_01++;
	}
	return (NULL);
}
