/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 17:44:17 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 20:58:39 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int verify)
{
	if ('A' <= verify && verify <= 'Z')
	{
		return (1);
	}
	else if ('a' <= verify && verify <= 'z')
	{
		return (1);
	}
	else if ('0' <= verify && verify <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
