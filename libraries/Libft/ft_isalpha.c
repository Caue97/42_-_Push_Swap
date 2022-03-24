/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:46:33 by felcaue-          #+#    #+#             */
/*   Updated: 2021/08/24 22:11:14 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int receive)
{
	if ('a' <= receive && receive <= 'z')
	{
		return (1);
	}
	else if ('A' <= receive && receive <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
