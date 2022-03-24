/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sequence&content_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:56:51 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:49:59 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sequence(t_list *list_a)
{
	int		prev;
	t_list	*next_a;

	if (!list_a)
		return (1);
	next_a = list_a;
	prev = next_a->content->value;
	while (next_a)
	{
		if (prev > next_a->content->value)
			return (0);
		prev = next_a->content->value;
		next_a = next_a->next;
	}
	return (1);
}

void	set_content_info(t_content *content)
{
	int	list_size;

	list_size = ft_lstsize(content->stack_a);
	content->length = list_size;
	content->total_nb = list_size;
	content->groups = max(1, list_size / 150);
	content->groups_len = list_size / content->groups;
	content->biggest_sequence = biggest_seq_tag(content->stack_a, 1);
}

static int	big_seq_tag(t_list *list, t_list *start, int tag)
{
	t_list	*loop;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	loop = start;
	while (loop)
	{
		if (tag)
			loop->content->tag_keep = 0;
		if (loop->content->index > max_tag)
		{
			max_tag = loop->content->index;
			count++;
			if (tag)
				loop->content->tag_keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = list;
		if (loop == start)
			break ;
	}
	return (count);
}

int	biggest_seq_tag(t_list *start, int tag)
{
	t_list	*t;
	int		max;
	int		count;
	t_list	*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = big_seq_tag(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (tag)
		big_seq_tag(start, max_keep, 1);
	return (max);
}
