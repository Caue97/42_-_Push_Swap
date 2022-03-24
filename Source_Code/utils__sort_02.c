/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils__sort_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:12:36 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:51:00 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	optimize_rotate(t_content *content, int *a_rot, int *b_rot)
{
	while (*a_rot > 0 && *b_rot > 0)
	{
		rr(content, PRINT_SORT);
		(*a_rot)--;
		(*b_rot)--;
	}
	while (*a_rot < 0 && *b_rot < 0)
	{
		rrr(content, PRINT_SORT);
		(*a_rot)++;
		(*b_rot)++;
	}
}

void	rotate(t_content *content, int a_rot, int b_rot)
{
	optimize_rotate(content, &a_rot, &b_rot);
	while (a_rot > 0)
	{
		ra(content, PRINT_SORT);
		a_rot--;
	}
	while (a_rot < 0)
	{
		rra(content, PRINT_SORT);
		a_rot++;
	}
	while (b_rot > 0)
	{
		rb(content, PRINT_SORT);
		b_rot--;
	}
	while (b_rot < 0)
	{
		rrb(content, PRINT_SORT);
		b_rot++;
	}
}
