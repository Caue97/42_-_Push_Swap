/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:06:04 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:55:36 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_next_ordered(t_list *prev, t_list *up)
{
	t_list	*next;

	next = up->content->next_ordered;
	up->content->next_ordered = next->content->next_ordered;
	next->content->next_ordered = up;
	prev->content->next_ordered = next;
}

static void	swap_next_ordered_begin(t_list **begin, t_list *up)
{
	t_list	*next;

	next = up->content->next_ordered;
	up->content->next_ordered = next->content->next_ordered;
	next->content->next_ordered = up;
	*begin = next;
}

static void	sort_list(t_list **begin)
{
	t_list	*iterator;
	t_list	*prev;

	prev = NULL;
	iterator = *begin;
	while (iterator && iterator->content->next_ordered)
	{
		if (iterator->content->value
			> iterator->content->next_ordered->content->value)
		{
			if (prev == NULL)
				swap_next_ordered_begin(&(*begin), iterator);
			else
				swap_next_ordered(prev, iterator);
			iterator = *begin;
			prev = NULL;
		}
		else
		{
			prev = iterator;
			iterator = iterator->content->next_ordered;
		}
	}
}

void	ft_index(t_list *list_init)
{
	int		i;
	t_list	*begin;

	begin = ft_lstlast(list_init);
	sort_list(&begin);
	i = 0;
	while (begin->content->next_ordered)
	{
		begin->content->index = i++;
		begin = begin->content->next_ordered;
	}
	begin->content->index = i;
}
