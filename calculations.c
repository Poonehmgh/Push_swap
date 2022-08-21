/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:22:20 by pooneh            #+#    #+#             */
/*   Updated: 2022/08/15 17:54:56 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	position_calc(t_stack_lst **a_head)
{
	t_stack_lst	*tmp;
	int			i;

	tmp = *a_head;
	i = 0;
	while (*a_head != NULL)
	{
		(*a_head)->position = i;
		i++;
		*a_head = (*a_head)->next;
	}
	*a_head = tmp;
}

t_stack_lst	*min_index_finder(t_stack_lst **a_head)
{
	t_stack_lst	*tmp;
	int			min;
	t_stack_lst	*node;

	tmp = *a_head;
	min = tmp->index;
	while (tmp->next != NULL)
	{
		if (tmp->index <= min)
		{
			min = tmp->index;
			node = tmp;
		}
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
	{
		if (tmp->index <= min)
		{
			min = tmp->index;
			node = tmp;
		}
	}
	return (node);
}

void	target_position2(t_stack_lst *tmp_b, t_stack_lst *tmp_a,
						int diff, t_stack_lst **a_head)
{
	int			indicator;

	indicator = 0;
	while (tmp_b != NULL)
	{
		while (tmp_a != NULL)
		{
			if (tmp_b->index < tmp_a->index)
			{
				if (((tmp_a->index) - (tmp_b->index)) <= diff)
				{
					diff = (tmp_a->index) - (tmp_b->index);
					tmp_b->desired_position = tmp_a->position;
					indicator = 1;
				}
			}
			tmp_a = tmp_a->next;
		}
		tmp_a = *a_head;
		if (indicator == 0)
			tmp_b->desired_position = (*min_index_finder(&tmp_a)).position;
		indicator = 0;
		tmp_b = tmp_b->next;
		diff = 2147483647;
	}
}

void	target_position(t_stack_lst **a_head, t_stack_lst **b_head)
{
	t_stack_lst	*tmp_a;
	t_stack_lst	*tmp_b;
	int			diff;

	tmp_a = *a_head;
	tmp_b = *b_head;
	diff = 2147483647;
	target_position2(tmp_b, tmp_a, diff, a_head);
}

void	cost_of_rotation_b(t_stack_lst **b_head)
{
	t_stack_lst	*tmp;
	int			number_of_nodes;

	tmp = *b_head;
	number_of_nodes = count_nodes(b_head);
	while (tmp != NULL)
	{
		if (tmp->position < number_of_nodes / 2)
			tmp->cost_b = tmp->position;
		else
				tmp->cost_b = -((number_of_nodes) - tmp->position) + 1;
		tmp = tmp->next;
	}
}
