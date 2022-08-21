/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:26:09 by pooneh            #+#    #+#             */
/*   Updated: 2022/08/14 17:46:12 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	count_nodes(t_stack_lst **a_head)
{
	t_stack_lst	*tmp;
	int			i;

	tmp = *a_head;
	i = 1;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	abs_value(int number)
{
	if (number < 0)
		number = -1 * number;
	return (number);
}

int	cheapest_element(t_stack_lst **b_head)
{
	int			cost;
	t_stack_lst	*tmp;
	int			selected_node;

	tmp = *b_head;
	cost = abs_value(tmp->cost_a) + abs_value(tmp->cost_b);
	selected_node = tmp->position;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		if (cost > abs_value(tmp->cost_a) + abs_value(tmp->cost_b))
		{
			cost = abs_value(tmp->cost_a) + abs_value(tmp->cost_b);
			selected_node = tmp->position;
		}
		tmp = tmp->next;
	}
	return (selected_node);
}

void	sort_for2(t_stack_lst **a_head)
{
	if ((*a_head)->number > (*a_head)->next->number)
		swap(a_head, 1);
	exit(0);
}

void	moving_to_b(t_stack_lst **a_head, t_stack_lst **b_head)
{
	t_stack_lst	*tmp;
	t_stack_lst	*tmp_b;

	tmp = *a_head;
	tmp_b = *b_head;
	while ((*a_head)->next->next->next != NULL)
	{
		push(b_head, a_head, 2);
	}
}
