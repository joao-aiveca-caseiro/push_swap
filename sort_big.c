/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:04 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 13:29:53 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_int_nearest(t_list **a, int chunk_top, int k)
{
	int		pos_first;
	int		pos_last;
	int		selected_pos;

	selected_pos = 0;
	pos_first = first_in_chunk_pos(a, chunk_top, k);
	pos_last = last_in_chunk_pos(a, chunk_top, k);
	if (ft_lstsize(a) - pos_last < pos_first)
		selected_pos = pos_last;
	else
		selected_pos = pos_first;
	return (selected_pos);
}

void	selected_to_head(t_list **a, t_list **b, int sel_pos, t_list **instr)
{	
	t_list	*temp;
	int		i;
	int		selected_index;

	temp = *a;
	if (ft_lstsize(a) > 1)
	{
		i = 0;
		while (i < sel_pos)
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

void	rot_b_before_push(t_list **a, t_list **b, t_list **instr)
{
	t_list	*temp;
	int		check;
	int		selected;
	int		i;

	temp = *b;
	check = 1;
	i = (*a)->index;
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
	if (check == 1)
		selected = find_max_index(b);
	else
		selected = find_index_below(b, i);
	temp_to_top(a, b, selected, instr);
}

void	from_a_to_b(t_list **a, t_list **b, t_list **instr, int chunk_size)
{
	int	i;
	int	j;
	int	selected_pos;

	i = 0;
	j = 1;

	while (*a)
	{
		while (*a && i < chunk_size * j)
		{
			selected_pos = chunk_int_nearest(a, chunk_size * j - 1, chunk_size);
			selected_to_head(a, b, selected_pos, instr);
			if (ft_lstsize(b) > 1)
				rot_b_before_push(a, b, instr);
			temp_push_pswap(a, b, 'b', instr);
			i++;
		}
		j++;
	}
}

void	sort_big_pswap(t_list **a, t_list **b, t_list **instr)
{
	int		chunk_size;

	arg_indexer(a);
	if (ft_lstsize(a) < 200)
		chunk_size = 20;
	else
		chunk_size = 40;
	if (check_if_sorted(a) == 0)
	{

		from_a_to_b(a, b, instr, chunk_size);
		while (*b)
			temp_push_pswap(b, a, 'a', instr);
		temp_min_to_head(a, b, instr);
	}
}
