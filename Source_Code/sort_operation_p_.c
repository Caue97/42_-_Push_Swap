/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operation_p_.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:45:17 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:07 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_content *content, int print)
{
	push_top(&(content->stack_b), &(content->stack_a));
	if (print)
	{
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_content *content, int print)
{
	push_top(&(content->stack_a), &(content->stack_b));
	if (print)
	{
		ft_putstr_fd("pb\n", 1);
	}
}
