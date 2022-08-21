/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:58:14 by pooneh            #+#    #+#             */
/*   Updated: 2022/08/14 17:45:03 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack_lst **A_head, int indicator)
{
	t_stack_lst	*tmp;
	t_stack_lst	*tmp2;

	tmp = (*A_head)->next;
	tmp2 = (**A_head).next->next;
	(*A_head)->next = tmp->next;
	tmp->next = *A_head;
	*A_head = tmp;
	ft_printf("s");
	if (indicator == 1)
		ft_printf("a\n");
	else
		ft_printf("b\n");
}

void	push(t_stack_lst **A_head, t_stack_lst **B_head, int indicator)
{
	t_stack_lst	*tmp;

	tmp = *B_head;
	*B_head = (**B_head).next;
	tmp->next = *A_head;
	*A_head = tmp;
	ft_printf("p");
	if (indicator == 1)
		ft_printf("a\n");
	else
		ft_printf("b\n");
}

void	rotate(t_stack_lst **A_head, int indicator)
{
	t_stack_lst	*tmp;
	t_stack_lst	*tmp2;

	tmp = *A_head;
	tmp2 = *A_head;
	*A_head = (**A_head).next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = tmp2;
	*A_head = tmp2->next;
	tmp2->next = NULL;
	if (indicator == 1)
		ft_printf("ra\n");
	else if (indicator == 2)
		ft_printf("rb\n");
}

void	reverse_r(t_stack_lst **A_head, int indicator)
{
	t_stack_lst	*tmp;
	t_stack_lst	*tmp2;
	t_stack_lst	*endpoint;

	tmp = *A_head;
	tmp2 = *A_head;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	endpoint = tmp->next;
	endpoint->next = tmp2;
	tmp2 = endpoint;
	tmp->next = NULL;
	*A_head = tmp2;
	if (indicator == 1)
		ft_printf("rra\n");
	else if (indicator == 2)
		ft_printf("rrb\n");
}
