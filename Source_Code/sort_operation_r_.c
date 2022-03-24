/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_r_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:39:38 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:15 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_content *content, int print)
{
	shift_up(&(content->stack_a));
	if (print)
	{
		ft_putstr_fd("ra\n", 1);
	}
}

void	rb(t_content *content, int print)
{
	shift_up(&(content->stack_b));
	if (print)
	{
		ft_putstr_fd("rb\n", 1);
	}
}

void	rr(t_content *content, int print)
{
	shift_up(&(content->stack_a));
	shift_up(&(content->stack_b));
	if (print)
	{
		ft_putstr_fd("rr\n", 1);
	}
}
