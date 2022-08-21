/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:29:08 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/08/14 18:12:36 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	execute_rotations2_b(t_stack_lst **b_head, int rot_b)
{
	while (rot_b != 0)
	{
		if (rot_b > 0)
		{
			rotate(b_head, 2);
			rot_b--;
		}
		else
		{
			reverse_r(b_head, 2);
			rot_b++;
		}
	}
}

void	execute_rotations2_a(t_stack_lst **a_head, int rot_a)
{
	while (rot_a != 0)
	{
		if (rot_a > 0)
		{
			rotate(a_head, 1);
			rot_a--;
		}
		else
		{
			reverse_r(a_head, 1);
			rot_a++;
		}
	}
}

void	execute_rotations(t_stack_lst **a_head,
							t_stack_lst **b_head, int rot_a, int rot_b)
{
	while (rot_a > 0 && rot_b > 0)
	{
		rotate_both(a_head, b_head);
		rot_a--;
		rot_b--;
	}
	while (rot_a < 0 && rot_b < 0)
	{
		reverse_r_both(a_head, b_head);
		rot_a++;
		rot_b++;
	}
	execute_rotations2_a(a_head, rot_a);
	execute_rotations2_b(b_head, rot_b);
}

void	execution(t_stack_lst **a_head, t_stack_lst **b_head, int position)
{
	t_stack_lst	*tmp_a;
	t_stack_lst	*tmp_b;
	int			rot_a;
	int			rot_b;

	tmp_a = *a_head;
	tmp_b = *b_head;
	if (!tmp_b)
		exit(0);
	while (tmp_b->position != position)
		tmp_b = tmp_b->next;
	rot_a = tmp_b->cost_a;
	rot_b = tmp_b->cost_b;
	execute_rotations(a_head, b_head, rot_a, rot_b);
	push(a_head, b_head, 1);
}

void	cost_of_rotation_a(t_stack_lst **a_head, t_stack_lst **b_head)
{
	t_stack_lst	*tmp;
	t_stack_lst	*tmp_b;
	int			number_of_nodes;

	tmp = *a_head;
	tmp_b = *b_head;
	number_of_nodes = count_nodes(a_head);
	while (tmp_b != NULL)
	{
		if (tmp_b->desired_position < number_of_nodes / 2)
			tmp_b->cost_a = tmp_b->desired_position;
		else
			tmp_b->cost_a = -((number_of_nodes) - tmp_b->desired_position) + 1;
		tmp_b = tmp_b->next;
	}
}
