/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 18:35:38 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 20:14:29 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_1, const char *str_2, size_t n_comp)
{
	size_t			counter;
	unsigned char	*first;
	unsigned char	*second;

	if (n_comp == 0)
	{
		return (0);
	}	
	counter = 0;
	first = (unsigned char *)str_1;
	second = (unsigned char *)str_2;
	while ((first[counter] || second[counter]) && counter < n_comp)
	{
		if (first[counter] != second[counter])
		{
			return (first[counter] - second[counter]);
		}
		counter++;
	}
	return (0);
}
