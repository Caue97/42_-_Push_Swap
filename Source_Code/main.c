/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:29:43 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:55:36 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_content	content;
	int			already_sorted;

	content.stack_a = NULL;
	content.stack_b = NULL;
	if (argc <= 1)
	{
		return (0);
	}
	check_args(argc, argv, &content);
	already_sorted = is_sequence(content.stack_a);
	if (already_sorted)
	{
		return (0);
	}
	ft_index(content.stack_a);
	set_content_info(&content);
	sorting(&content);
	clean(&content);
	return (0);
}
