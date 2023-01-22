/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:01 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 01:20:39 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_pswap(t_list **a, t_list **b)
{
	while (check_if_sorted(a) == 0)
	{
		swap_pswap(a, b, 'a');
	}
}

void	sort_3_pswap(t_list **a, t_list **b)
{
	while (check_if_sorted(a) == 0)
	{
		if ((*a)->content > (*a)->next->content
			&& (*a)->content > (*a)->next->next->content)
			rotate_pswap(a, b, 'a');
		if ((*a)->content > (*a)->next->content)
			swap_pswap(a, b, 'a');
		if ((*a)->next->content > (*a)->next->next->content)
			revrotate_pswap(a, b, 'a');
	}
}

void	sort_upto5_pswap(t_list **a, t_list **b)
{
	if (check_if_sorted(a) == 0)
	{
		min_to_head(a, b);
		push_pswap(a, b, 'b');
		if (ft_lstsize(a) == 4)
		{
			min_to_head(a, b);
			push_pswap(a, b, 'b');
		}
		sort_3_pswap(a, b);
		while (*b)
		{
			push_pswap(b, a, 'a');
		}
	}
}
