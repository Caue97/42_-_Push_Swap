/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:25:43 by felcaue-          #+#    #+#             */
/*   Updated: 2021/09/05 18:12:31 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	convt_to_number(int n_conv, char *d_str, long int length);

char	*ft_itoa(int n)
{
	char		*ret_strng;
	long int	num_og_c;
	long int	len_count;

	num_og_c = n;
	len_count = 0;
	if (num_og_c <= 0)
	{
		len_count++;
	}
	while (num_og_c)
	{
		num_og_c = (num_og_c / 10);
		len_count++;
	}
	ret_strng = malloc(sizeof(char) * (len_count + 1));
	if (!ret_strng)
	{
		return (NULL);
	}
	ret_strng[len_count] = 0;
	convt_to_number(n, ret_strng, (len_count - 1));
	return (ret_strng);
}

static void	convt_to_number(int n_conv, char *d_str, long int length)
{
	unsigned int	n_holder;

	n_holder = n_conv;
	if (n_conv < 0)
	{
		d_str[0] = '-';
		n_holder = -n_holder;
	}
	if (n_holder >= 10)
	{
		convt_to_number((n_holder / 10), d_str, (length - 1));
	}
	d_str[length] = (n_holder % 10) + '0';
}
