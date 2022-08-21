/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:19:07 by pooneh            #+#    #+#             */
/*   Updated: 2022/08/14 17:44:47 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_strlen_arr(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	index_apply2list(t_stack_lst	**a_head, int *arr, int count)
{
	int			i;
	t_stack_lst	*head;

	head = *a_head;
	i = 0;
	while ((*a_head) != NULL)
	{
		while (i <= count)
		{
			if ((*a_head)->number == arr[i])
			{
				(*a_head)->index = i;
				break ;
			}
			i++;
		}
		i = 0;
		*a_head = (*a_head)->next;
	}
	*a_head = head;
}

void	index_provider(int *arr, t_stack_lst **a_head, int count)
{
	int	j;
	int	i;
	int	key;

	j = 1;
	while (j <= count)
	{
		i = j;
		key = arr[j];
		while (i > 0 && arr[i - 1] >= key)
		{
			arr[i] = arr[i - 1];
			arr[i - 1] = key;
			i--;
		}
		j++;
	}
	index_apply2list(a_head, arr, count);
}

t_stack_lst	*new_node(int new)
{
	t_stack_lst	*result;

	result = malloc(sizeof(t_stack_lst));
	if (!result)
		return (0);
	result->number = new;
	result->next = NULL;
	return (result);
}

// void	stack_print(t_stack_lst *A)
// {
// 	t_stack_lst	*tmp;

// 	tmp = A;
// 	while (tmp != NULL)
// 	{
// 		printf("Stack items:%d\n",tmp->number);
// 		tmp = tmp->next;
// 	}
// }

// void	stack_full_print(t_stack_lst *A)
// {
// 	t_stack_lst	*tmp;

// 	tmp = A;
// 	while (tmp)
// 	{
// 		printf("%d positions: %d index: %d desired: %d, cost B:%d, cost A:%d\n", 
// 			tmp->number, tmp->position, tmp->index, tmp->desired_position,
// 			tmp->cost_B, tmp->cost_A);
// 		tmp = tmp->next;
// 	}
// 	tmp = A;
// }
