/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:57:11 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:50:46 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	should_swap(t_list *list)
{
	t_list	swap_b;
	t_list	swap_a;
	int		without_swap;
	int		with_swap;
	int		should_swap;

	swap_b.next = &swap_a;
	swap_b.content = malloc(sizeof(t_info));
	(swap_b.content)->index = list->next->content->index;
	swap_a.next = list->next->next;
	swap_a.content = malloc(sizeof(t_info));
	(swap_a.content)->index = list->content->index;
	without_swap = biggest_seq_tag(list, 0);
	with_swap = biggest_seq_tag(&swap_b, 0);
	should_swap = with_swap > without_swap;
	free(swap_b.content);
	free(swap_a.content);
	return (should_swap);
}

static void	actions(t_content *content, int top_distance)
{
	if (content->stack_a && should_swap(content->stack_a))
	{
		sa(content, PRINT_SORT);
		content->biggest_sequence = biggest_seq_tag(content->stack_a, 1);
	}
	else if (content->stack_a && !content->stack_a->content->tag_keep
		&& top_distance == 0)
	{
		pb(content, PRINT_SORT);
		(content->length)--;
	}
	else if (content->groups == 1)
		rr(content, PRINT_SORT);
	else
		rotate(content, min(1, max(-1, top_distance)), 0);
}

static void	improve(t_content *content)
{
	if (content->length == 5 && content->biggest_sequence == 2
		&& should_swap(content->stack_a)
		&& content->stack_a->content->index == 1)
		rra(content, PRINT_SORT);
}

static void	refill_a_from_b(t_content *content)
{
	int	a_rot;
	int	b_rot;

	while (content->stack_b)
	{
		set_rotation(content, MAX_INT, &a_rot, &b_rot);
		rotate(content, a_rot, b_rot);
		pa(content, PRINT_SORT);
		(content->length)++;
	}
	rotate(content, distance_to_index(content->stack_a, 0), 0);
}

void	sorting(t_content *content)
{
	int	top_distance;
	int	actual_group;

	actual_group = 1;
	improve(content);
	while (content->length >= content->biggest_sequence
		&& actual_group <= (content->groups + 1))
	{
		content->stack_a_ref = get_closest_group(content->stack_a, \
				actual_group, content->groups_len);
		if (content->stack_a_ref == NULL && ++actual_group)
			continue ;
		top_distance = distance_to_index(content->stack_a, \
				content->stack_a_ref->content->index);
		actions(content, top_distance);
	}
	refill_a_from_b(content);
}
