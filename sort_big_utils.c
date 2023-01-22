/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 04:03:51 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 05:33:24 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_below(t_list **b, int i)
{
	t_list	*temp;
	int		selected;

	temp = *b;
	while (temp)
	{
		while (temp->next && i - 1 != temp->index)
			temp = temp->next;
		if (i - 1 == temp->index)
		{
			selected = temp->index;
			break ;
		}
		temp = *b;
		i--;
	}
	return (selected);
}

int	find_max_index(t_list **b)
{
	t_list	*temp;
	int		max;

	max = 0;
	temp = *b;
	while (temp)
	{
		if (max < temp->index)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	last_in_chunk_pos(t_list **a, int chunk_top, int k)
{
	t_list	*temp;
	int		last_in_chunk;
	int		pos_last;

	pos_last = 0;
	last_in_chunk = -1;
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
			pos_last++;
			temp = temp->next;
		}
	}
	return (pos_last);
}

int	first_in_chunk_pos(t_list **a, int chunk_top, int k)
{
	t_list	*temp;
	int		pos_first;

	pos_first = 0;
	temp = *a;
	while (temp && (temp->index > chunk_top || temp->index < chunk_top - k + 1))
	{
		pos_first++;
		temp = temp->next;
	}
	return (pos_first);
}

