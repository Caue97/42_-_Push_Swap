/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:47:11 by felcaue-          #+#    #+#             */
/*   Updated: 2022/03/23 18:52:15 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	validate_duplicated(t_list *list, int value)
{
	t_info	*compare_list;

	while (list)
	{
		compare_list = list->content;
		if (compare_list->value == value)
		{
			return (1);
		}
		list = list->next;
	}
	return (0);
}

static void	validate(char **argv, t_content *content, t_info *info, int i)
{
	int	j;

	j = -1;
	while (argv[i][++j])
	{
		if (argv[i][j] != '+' && argv[i][j] != '-'
			&& argv[i][j] != ' ' && !ft_isdigit(argv[i][j]))
		{
			validation_error(content, info, argv, i);
		}
	}
	if (validate_duplicated(content->stack_a, info->value))
	{
		validation_error(content, info, argv, i);
	}
	if (content->is_string_params)
	{
		free(argv[i]);
	}
}

static void	parse_nbrs(char **argv, t_content *content)
{
	int		i;
	t_info	*info;
	t_list	*i_list;
	t_list	*last_item;

	i = 0;
	while (argv[++i])
	{
		info = malloc(sizeof(t_info));
		info->value = atoi_safe(content, argv, info, i);
		validate(argv, content, info, i);
		if (i == 1)
			info->next_ordered = NULL;
		else
		{
			info->next_ordered = last_item;
		}
		i_list = ft_lstnew(info);
		if (i == 1)
			content->stack_a = i_list;
		else
			ft_lstadd_back(&last_item, i_list);
		last_item = i_list;
	}
}

static void	parse_str(char **argv, t_content *content)
{
	int		i;
	t_info	*info;
	t_list	*i_list;
	t_list	*last_item;

	i = -1;
	while (argv[++i])
	{
		info = malloc(sizeof(t_info));
		info->value = atoi_safe(content, argv, info, i);
		validate(argv, content, info, i);
		if (i == 0)
			info->next_ordered = NULL;
		else
		{
			info->next_ordered = last_item;
		}
		i_list = ft_lstnew(info);
		if (i == 0)
			content->stack_a = i_list;
		else
			ft_lstadd_back(&last_item, i_list);
		last_item = i_list;
	}
}

void	check_args(int argc, char **argv, t_content *content)
{
	if (argc == 2 && argv[1][0] > 9)
	{
		argv = ft_split(argv[1], ' ');
		if (!*argv)
		{
			free(argv);
			error(content);
		}
		content->is_string_params = 1;
		parse_str(argv, content);
		free(argv);
	}
	else
	{
		content->is_string_params = 0;
		parse_nbrs(argv, content);
	}
	return ;
}
