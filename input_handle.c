/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:07:24 by pooneh            #+#    #+#             */
/*   Updated: 2022/08/15 20:37:47 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	*array_maker(char **argv, int argc, t_stack_lst **head_a)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * argc);
	if (!arr)
		return (0);
	i = 1;
	while (argv[i])
	{
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	index_provider(arr, head_a, argc - 2);
	return (arr);
}

void	duplicate_check(int *arr, int argc)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= argc - 2)
	{
		while (j <= argc -2)
		{
			if ((arr[i] == arr[j] && i != j))
			{
				ft_printf("Error\n");
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	float_check(int argc, char **argv)
{
	int	i;
	int	j;
	int	l;

	i = 1;
	j = 0;
	while (i < argc)
	{
		l = (int)ft_strlen(argv[i]);
		while (j < l)
		{
			if (argv[i][j] == '.')
			{
				ft_printf ("Error\n");
				exit(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	input_handling(int argc, char **argv, t_stack_lst	**head_a)
{
	int	i;
	int	*arr;

	i = 1;
	while (i < argc)
	{
		if (!ft_atoi(argv[i]))
		{
			if (!zero_check(argv[i]))
			{
				ft_printf ("Error\n");
				exit(0);
			}
		}
		i++;
	}
	float_check(argc, argv);
	arr = array_maker(argv, argc, head_a);
	duplicate_check(arr, argc);
	free(arr);
}

void	argument_handling(char **argv, int *argc, t_stack_lst **head_a)
{
	char	**arg_str;
	int		i;

	i = 1;
	arg_str = ft_split(argv[1], ' ');
	if (ft_strlen_arr(arg_str) == 1)
	{
		input_handling(*argc, argv, head_a);
		exit (0);
	}
	while (arg_str[i - 1])
	{
		argv[i] = ft_strdup(arg_str[i - 1]);
		free (arg_str[i - 1]);
		i++;
	}
	free (arg_str);
	argv[i] = NULL;
	*argc = i;
}
