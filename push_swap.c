/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:40 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/08/15 20:43:15 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	sort_for3(t_stack_lst **a_head)
{
	if ((**a_head).number > (**a_head).next->number)
	{
		if ((**a_head).next->number < (**a_head).next->next->number)
			rotate(a_head, 1);
		else
			swap(a_head, 1);
	}
	if ((**a_head).number > (**a_head).next->number
		&& (**a_head).next->number > (**a_head).next->next->number)
		reverse_r(a_head, 1);
	else if ((**a_head).number > (**a_head).next->number
		&& (**a_head).next->number < (**a_head).next->next->number)
		rotate(a_head, 1);
	else if ((**a_head).number < (**a_head).next->number
		&& (**a_head).next->number > (**a_head).next->next->number)
	{
		if ((**a_head).number > (**a_head).next->next->number)
			reverse_r(a_head, 1);
		else
		{
			swap(a_head, 1);
			rotate(a_head, 1);
		}
	}
}

void	final_rotation_a(t_stack_lst **a_head, int node_amount)
{
	t_stack_lst	*tmp;
	int			position;

	position_calc(a_head);
	tmp = *a_head;
	while (tmp->index != 0)
		tmp = tmp->next;
	position = tmp->position;
	tmp = *a_head;
	if (position <= node_amount / 2)
	{
		while ((*a_head)->index != 0)
			rotate(a_head, 1);
	}
	else
	{
		while ((*a_head)->index != 0)
			reverse_r(a_head, 1);
	}
}

void	control_room(t_stack_lst **a_head, t_stack_lst **b_head)
{
	t_stack_lst	*tmp_b;

	tmp_b = *b_head;
	while (tmp_b)
	{
		position_calc(a_head);
		position_calc(b_head);
		target_position(a_head, b_head);
		cost_of_rotation_b(b_head);
		cost_of_rotation_a(a_head, b_head);
		execution(a_head, b_head, cheapest_element(b_head));
		tmp_b = *b_head;
		if (tmp_b)
			tmp_b = tmp_b->next;
	}
	if (tmp_b == NULL)
	{
		position_calc(a_head);
		position_calc(b_head);
		target_position(a_head, b_head);
		cost_of_rotation_b(b_head);
		cost_of_rotation_a(a_head, b_head);
		execution(a_head, b_head, 0);
		tmp_b = *b_head;
	}
}

void	sort_for4(t_stack_lst	**a_head, t_stack_lst	**b_head)
{
	t_stack_lst	*tmp_a;
	t_stack_lst	*tmp_b;

	tmp_a = *a_head;
	tmp_b = *b_head;
	while (tmp_b->index > tmp_a->index && tmp_b->index != 3)
	{
		rotate(a_head, 1);
		tmp_a = *a_head;
	}
	if (tmp_b->index != 3)
	{
		push(a_head, b_head, 1);
	}	
	while ((*a_head)->index != 0)
		rotate(a_head, 1);
	if (tmp_b->index == 3)
	{
		push(a_head, b_head, 1);
		rotate(a_head, 1);
	}
}

int	main(int argc, char **argv)
{
	t_stack_lst	*head_a;
	t_stack_lst	*head_b;
	int			*arrr;
	int			oldargc;

	oldargc = argc;
	if (argc == 1)
		exit (0);
	if (argc == 2)
		argument_handling(argv, &argc, &head_a);
	input_handling(argc, argv, &head_a);
	make_list(argc, argv, &head_a);
	if (argc == 3)
		sort_for2(&head_a);
	arrr = array_maker(argv, argc, &head_a);
	moving_to_b(&head_a, &head_b);
	sort_for3(&head_a);
	if (argc == 5)
		sort_for4(&head_a, &head_b);
	if (argc > 5)
	{
		control_room(&head_a, &head_b);
		final_rotation_a(&head_a, argc - 2);
	}
	free_stuff(arrr, argv, oldargc, head_a);
}
