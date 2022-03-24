/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:48:36 by felcaue-          #+#    #+#             */
/*   Updated: 2021/08/24 21:49:41 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	n_d_letras;

	if (str == NULL)
	{
		return (0);
	}
	n_d_letras = 0;
	while (str[n_d_letras] != '\0')
	{
		n_d_letras++;
	}
	return (n_d_letras);
}
