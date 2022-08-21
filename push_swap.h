/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoghadd <pmoghadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:16:09 by pmoghadd          #+#    #+#             */
/*   Updated: 2022/08/15 17:59:13 by pmoghadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "libft/libft.h"

typedef struct t_stack_lst
{
	int					number;
	int					index;
	int					position;
	int					desired_position;
	int					cost_a;
	int					cost_b;
	struct t_stack_lst	*next;
}t_stack_lst;

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

/*moves*/

void		swap(t_stack_lst **A_head, int indicator);
void		push(t_stack_lst **A_head, t_stack_lst **B_head, int indicator);
void		rotate(t_stack_lst **A_head, int indicator);
void		reverse_r(t_stack_lst **A_head, int indicator);
void		rotate_both(t_stack_lst	**A_head, t_stack_lst **B_head);
void		reverse_r_both(t_stack_lst	**A_head, t_stack_lst **B_head);
void		swap_both(t_stack_lst **A_head, t_stack_lst **B_head);

/*input handle*/

int			*array_maker(char **argv, int argc, t_stack_lst **head_a);
void		duplicate_check(int *arr, int argc);
void		float_check(int argc, char **argv);
void		input_handling(int argc, char **argv, t_stack_lst **head_a);
void		argument_handling(char **argv, int *argc, t_stack_lst **head_a);

/*input_process*/

void		index_provider(int *arr, t_stack_lst **A_head, int count);
int			ft_strlen_arr(char **s);
t_stack_lst	*new_node(int new);
/*void	stack_full_print(t_stack_lst *A);
void	stack_print(t_stack_lst *A);*/

/*calculations*/

void		position_calc(t_stack_lst **A_head);

void		target_position2(t_stack_lst *tmp_b, t_stack_lst *tmp_a,
				int diff, t_stack_lst **a_head);
void		target_position(t_stack_lst **A_head, t_stack_lst **B_head);
void		cost_of_rotation_b(t_stack_lst **B_head);
t_stack_lst	*min_index_finder(t_stack_lst **A_head);
/*utils*/

int			count_nodes(t_stack_lst	**A_head);
int			abs_value(int number);
int			cheapest_element(t_stack_lst **B_head);
void		sort_for2(t_stack_lst **A_head);
void		moving_to_b(t_stack_lst **A_head, t_stack_lst **B_head);

/*executions*/
void		execute_rotations2_b(t_stack_lst **b_head, int rot_b);
void		execute_rotations2_a(t_stack_lst **a_head, int rot_a);
void		execute_rotations(t_stack_lst **a_head,
				t_stack_lst **b_head, int rot_a, int rot_b);
void		execution(t_stack_lst **a_head, t_stack_lst **b_head, int position);
void		cost_of_rotation_a(t_stack_lst **A_head, t_stack_lst **B_head);

/*list*/
void		make_list(int argc, char **argv,
				t_stack_lst **head_a);
int			zero_check(char	*argv_i);
void		free_list(t_stack_lst *head_a);
void		free_array(char **argv);
void		free_stuff(int *arrr, char **argv, int oldargc,
				t_stack_lst *head_a);
#endif