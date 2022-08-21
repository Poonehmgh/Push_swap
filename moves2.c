/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:03:45 by pooneh            #+#    #+#             */
/*   Updated: 2022/08/14 18:13:03 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_lst	**a_head, t_stack_lst **b_head)
{
	rotate(a_head, 3);
	rotate(b_head, 3);
	ft_printf("rr\n");
}

void	reverse_r_both(t_stack_lst	**a_head, t_stack_lst **b_head)
{
	reverse_r(a_head, 3);
	reverse_r(b_head, 3);
	ft_printf("rrr\n");
}

void	swap_both(t_stack_lst **a_head, t_stack_lst **b_head)
{
	swap(a_head, 3);
	swap(b_head, 3);
	ft_printf("ss\n");
}
