/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_rr_.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:45:38 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:22 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_content *content, int print)
{
	shift_down(&(content->stack_a));
	if (print)
	{
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(t_content *content, int print)
{
	shift_down(&(content->stack_b));
	if (print)
	{
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(t_content *content, int print)
{
	shift_down(&(content->stack_b));
	shift_down(&(content->stack_a));
	if (print)
	{
		ft_putstr_fd("rrr\n", 1);
	}
}
