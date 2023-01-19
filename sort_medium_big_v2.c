/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_big_v2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:04 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/19 03:41:33 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	temp_chunk_int_node(t_list **a, int chunk_top, int k)
{
	t_list	*temp;
	int		pos_top;
	int		pos_bottom;
	int		selected_pos;
	int		last_in_chunk;

	temp = *a;
	pos_top = 0;
	pos_bottom = 0;
	selected_pos = 0;
	last_in_chunk = -1;
	while (temp && (temp->index > chunk_top || temp->index < chunk_top - k + 1))
	{
		pos_top++;
		temp = temp->next;
	}
	temp = *a;
	while (temp)
	{
		if (temp->index < chunk_top && temp->index > chunk_top - k + 1)
			last_in_chunk = temp->index;
		temp = temp->next;
	}
	temp = *a;
	if (last_in_chunk != -1)
	{
		while (temp->index != last_in_chunk)
		{
			pos_bottom++;
			temp = temp->next;
		}
	}
	if (ft_lstsize(a) - pos_bottom >= 0 && ft_lstsize(a) - pos_bottom < pos_top)
		selected_pos = pos_bottom;
	else
		selected_pos = pos_top;
	return (selected_pos);
}

void	temp_selected_to_head(t_list **a, t_list **b, int chunk_top, int k, t_list **instr)
{	
	t_list	*temp;
	int		i;
	int		selected_pos;
	int		selected_index;

	temp = *a;
	if (ft_lstsize(a) > 1)
	{
		selected_pos = temp_chunk_int_node(a, chunk_top, k);
		i = 0;
		while (i < selected_pos)
		{
			i++;
			temp = temp->next;
		}
		selected_index = temp->index;
		while ((*a)->index != selected_index)
		{
			if (i < ft_lstsize(a) / 2)
				temp_rotate_pswap(a, b, 'a', instr);
			else
				temp_revrotate_pswap(a, b, 'a', instr);
		}
	}
}

void	temp_rot_b_before_push(t_list **a, t_list **b, t_list **instr)
{
	t_list	*temp;
	int		check;
	int		max;
	int		i;

	temp = *b;
	check = 1;
	max = 0;
	i = (*a)->index;
	// check if index smaller than all indexes in b
	while (temp)
	{
		if (i > temp->index)
		{
			check = 0;
			break ;
		}
		temp = temp->next;
	}
	temp = *b;
	// if true look for index of the bigger element in b
	if (check == 1)
	{
		while (temp)
		{
			if (max < temp->index)
				max = temp->index;
			temp = temp->next;
		}
	}
	else
	// if false look for index of the smaller number closest to a
	{
		while (temp)
		{
			while (temp->next && i - 1 != temp->index)
				temp = temp->next;
			if (i - 1 == temp->index)
			{
				max = temp->index;
				break ;
			}
			temp = *b;
			i--;
		}
	}
	temp_to_top(a, b, max, instr);
}

void	temp_sort_big_pswap(t_list **a, t_list **b, t_list **instr)
{
	int		i;
	int		j;
	int		k;
	t_list	*temp_a;
	t_list	*temp_b;

	i = 0;
	j = 1;
	temp_a = *a;
	temp_b = *b;
	arg_indexer(&temp_a);
//	ft_printf("Before\n");
//	print_stack(a);
	if (ft_lstsize(&temp_a) < 200)
		k = 20;
	else
		k = 40;
	if (check_if_sorted(&temp_a) == 0)
	{
		while (temp_a)
		{
			while (temp_a && i < k * j)
			{
				temp_selected_to_head(&temp_a, &temp_b, k * j - 1, k, instr);
				if (ft_lstsize(&temp_b) > 1)
					temp_rot_b_before_push(&temp_a, &temp_b, instr);
				temp_push_pswap(&temp_a, &temp_b, 'b', instr);
				i++;
			}
			j++;
		}
		while (temp_b)
			temp_push_pswap(&temp_b, &temp_a, 'a', instr);
		temp_min_to_head(&temp_a, &temp_b, instr);
	}
	print_stack(&temp_a);
	ft_printf("Stack A\n");
	print_stack(a);
//	optimizer_pswap(a, b, instr);
}
