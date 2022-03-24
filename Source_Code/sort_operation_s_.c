/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_s_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:45:14 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:38 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_content *content, int print)
{
	swap(&(content->stack_a));
	if (print)
	{
		ft_putstr_fd("sa\n", 1);
	}
}

void	sb(t_content *content, int print)
{
	swap(&(content->stack_b));
	if (print)
	{
		ft_putstr_fd("sb\n", 1);
	}
}

void	ss(t_content *content, int print)
{
	swap(&(content->stack_b));
	swap(&(content->stack_a));
	if (print)
	{
		ft_putstr_fd("ss\n", 1);
	}
}
