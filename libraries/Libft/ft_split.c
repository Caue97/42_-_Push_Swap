/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:25:43 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 20:44:34 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	w_count(char const *str_og, char create_div);
static size_t	l_count(const char *str_part, char div);

char	**ft_split(char const *s, char c)
{
	size_t		divisions;
	char		**ret_arr;
	int			counter_l;

	if (!s)
		return (0);
	divisions = w_count(s, c);
	ret_arr = ft_calloc(divisions + 1, sizeof(char *));
	if (!ret_arr)
		return (0);
	counter_l = -1;
	divisions = 0;
	while (s[++counter_l])
	{
		if (s[counter_l] != c && s[counter_l] != '\0')
		{
			ret_arr[divisions] = ft_substr(s, counter_l,
					l_count(&s[counter_l], c));
			++divisions;
			counter_l = counter_l + l_count(&s[counter_l], c) - 1;
		}
	}
	return (ret_arr);
}

static size_t	w_count(char const *str_og, char create_div)
{
	size_t		le_count;
	size_t		words;
	size_t		flag;
	size_t		begin;

	le_count = 0;
	words = 0;
	flag = 0;
	while (str_og[le_count])
	{
		begin = flag;
		if (str_og[le_count] == create_div)
			flag = 0;
		else
			flag = 1;
		if (begin != flag && begin == 1)
			++words;
		++le_count;
	}
	if (flag == 1)
	{
		++words;
	}
	return (words);
}

static size_t	l_count(const char *str_part, char div)
{
	int	counter_l;

	counter_l = 0;
	while (str_part[counter_l] != div && str_part[counter_l] != '\0')
	{
		++counter_l;
	}
	return (counter_l);
}
