/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils__sort_03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:14:34 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:51:08 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **init_ref)
{
	t_list	*swap;
	t_list	*third;

	if (!*init_ref || !(*init_ref)->next)
		return ;
	third = (*init_ref)->next->next;
	swap = *init_ref;
	*init_ref = (*init_ref)->next;
	(*init_ref)->next = swap;
	swap->next = third;
}

void	push_top(t_list **init_ref_1, t_list **init_ref_2)
{
	t_list	*top;

	if (!*init_ref_1)
		return ;
	top = *init_ref_1;
	*init_ref_1 = top->next;
	if (*init_ref_2)
		top->next = *init_ref_2;
	else
		top->next = NULL;
	*init_ref_2 = top;
}

void	shift_up(t_list **init_ref)
{
	t_list	*top;
	t_list	*last;

	if (!*init_ref || !(*init_ref)->next)
		return ;
	top = *init_ref;
	*init_ref = (*init_ref)->next;
	last = ft_lstlast(*init_ref);
	last->next = top;
	top->next = NULL;
}

void	shift_down(t_list **init_ref)
{
	t_list	*last;
	t_list	*prev;

	if (!*init_ref || !(*init_ref)->next)
		return ;
	last = *init_ref;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *init_ref;
	*init_ref = last;
	prev->next = NULL;
}
