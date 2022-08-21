/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 15:34:59 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/08/15 17:42:31 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	make_list(int argc, char **argv,
			t_stack_lst **head_a)
{
	t_stack_lst	*stack_a;
	t_stack_lst	*tmp;
	int			i;

	i = 1;
	*head_a = new_node(ft_atoi(argv[1]));
	tmp = *head_a;
	while (i < argc - 1)
	{
		(tmp) = (*head_a);
		stack_a = new_node(ft_atoi(argv[i + 1]));
		while ((tmp)->next != NULL)
			tmp = (tmp)->next;
		(tmp)->next = stack_a;
		i++;
	}
}

int	zero_check(char	*argv_i)
{
	int	i;

	i = 1;
	while (argv_i[i])
	{
		if (argv_i[i] != '0')
			return (0);
	i++;
	}
	if (argv_i[0] == '0' || ((argv_i[0] == '+' || argv_i[0] == '-')
			&& argv_i[1] != '\0'))
		return (1);
	if (argv_i[0] != '0')
		return (0);
	return (0);
}

void	free_array(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
}

void	free_list(t_stack_lst *head_a)
{
	t_stack_lst	*tmp;

	while (head_a)
	{
		tmp = (head_a)->next;
		free(head_a);
		head_a = tmp;
	}
}

void	free_stuff(int *arrr, char **argv, int oldargc, t_stack_lst *head_a)
{
	free(arrr);
	if (oldargc == 2)
		free_array(argv);
	free_list(head_a);
}
