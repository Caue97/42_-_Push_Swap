/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:56:11 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:49:31 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean(t_content *content)
{
	if (content->stack_a)
		ft_lstclear(&(content->stack_a), free);
	if (content->stack_b)
		ft_lstclear(&(content->stack_b), free);
}

void	error(t_content *content)
{
	ft_putstr_fd("Error\n", 2);
	clean(content);
	exit(EXIT_FAILURE);
}

void	validation_error(t_content *content, t_info *inf, char **argv, int i)
{
	free(inf);
	if (content->is_string_params)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	error(content);
}
