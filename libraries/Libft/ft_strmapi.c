/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:15:45 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 20:55:58 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*ret_str;

	count = 0;
	if (!s)
	{
		return (NULL);
	}
	ret_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!ret_str)
	{
		return (NULL);
	}
	while (s[count] != '\0')
	{
		ret_str[count] = f(count, s[count]);
		count++;
	}
	ret_str[count] = '\0';
	return (ret_str);
}
