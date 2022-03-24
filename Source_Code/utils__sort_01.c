/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils__sort_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:07:34 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:59:14 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}

t_list	*get_closest_group(t_list *list, int actual_group, int group_total)
{
	t_list	*closest;
	t_list	*cur;
	int		distance;
	int		cur_dist;

	distance = MAX_INT;
	closest = NULL;
	cur = list;
	while (cur)
	{
		if (cur->content->index <= group_total * actual_group
			&& !cur->content->tag_keep)
		{
			cur_dist = distance_to_index(list, cur->content->index);
			if (abs(cur_dist) < abs(distance))
			{
				distance = cur_dist;
				closest = cur;
				if (distance == 0)
					break ;
			}
		}
		cur = cur->next;
	}
	return (closest);
}

static int	get_distance(t_list *list, int t, int size)
{
	t_list	*p;
	t_list	*c;
	int		c_max[3];

	c_max[2] = 0;
	p = ft_lstlast(list);
	c = list;
	c_max[1] = MAX_INT;
	while (c)
	{
		if ((p->content->index > c->content->index \
				&& (t < c->content->index || t > p->content->index)) \
				|| (t > p->content->index && t < c->content->index))
		{
			c_max[0] = c_max[2];
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (abs(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		c_max[2]++;
	}
	return (c_max[1]);
}

void	set_rotation(t_content *cont, int max_dist, int *a_rot, int *b_rot)
{
	int	dist_total;
	int	insert;
	int	distance_b;
	int	i;

	i = 0;
	cont->stack_a_ref = cont->stack_b;
	while (cont->stack_a_ref)
	{
		distance_b = distance_to_tag(i++, cont->total_nb - cont->length);
		insert = get_distance(cont->stack_a, \
				cont->stack_a_ref->content->index, cont->length);
		dist_total = abs(insert) + abs(distance_b);
		if (insert > 0 && distance_b > 0)
			dist_total -= min(distance_b, insert);
		if (insert < 0 && distance_b < 0)
			dist_total += max(distance_b, insert);
		if (dist_total < max_dist)
		{
			max_dist = dist_total;
			*a_rot = insert;
			*b_rot = distance_b;
		}
		cont->stack_a_ref = cont->stack_a_ref->next;
	}
}

int	distance_to_index(t_list *list, int index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(list);
	while (list)
	{
		if (list->content->index == index)
			break ;
		list = list->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}
