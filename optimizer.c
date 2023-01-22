/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:31:59 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 01:19:26 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimizer_pswap(t_list **a, t_list **b, t_list **instr)
{
	while (*instr)
	{
		if ((*instr)->content == 2
			&& (*instr)->next && (*instr)->next->content == 1)
			to_next_and_delete_curr(instr);
		else if ((*instr)->content == 1)
			push_pswap(b, a, 'a');
		else if ((*instr)->content == 2)
			push_pswap(a, b, 'b');
		else if ((*instr)->content == 4)
			rotate_pswap(b, a, 'b');
		else if ((*instr)->content == 6)
			revrotate_pswap(b, a, 'b');
		else if ((*instr)->content == 3)
			rotate_optimizer_pswap(a, b, instr, 3);
		else if ((*instr)->content == 5)
			rotate_optimizer_pswap(a, b, instr, 5);
		to_next_and_delete_curr(instr);
	}
}

void	to_next_and_delete_curr(t_list **instr)
{
	t_list	*temp;

	temp = *instr;
	*instr = (*instr)->next;
	ft_lstdelone(temp, NULL);
}

void	rotate_optimizer_pswap(t_list **a, t_list **b, t_list **instr, int move)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if ((*instr)->content == move)
	{
		while ((*instr)->next && (*instr)->next->content == move)
		{
			to_next_and_delete_curr(instr);
			i++;
		}
		while ((*instr)->next && (*instr)->next->content == move + 1)
		{
			to_next_and_delete_curr(instr);
			j++;
		}
	}
	if (move == 3)
		r_optimized_pswap(a, b, i, j);
	else if (move == 5)
		revr_optimized_pswap(a, b, i, j);
}

void	r_optimized_pswap(t_list **a, t_list **b, int i, int j)
{
	while (i > 0 || j > 0)
	{
		if (i > 0 && j > 0)
		{
			rotate_pswap(a, b, 'r');
			j--;
			i--;
		}
		else if (i > 0 && j <= 0)
		{
			rotate_pswap(a, b, 'a');
			i--;
		}
		else if (i <= 0 && j > 0)
		{
			rotate_pswap(b, a, 'b');
			j--;
		}
	}
}

void	revr_optimized_pswap(t_list **a, t_list **b, int i, int j)
{
	while (i > 0 || j > 0)
	{
		if (i > 0 && j > 0)
		{
			revrotate_pswap(a, b, 'r');
			j--;
			i--;
		}
		else if (i > 0 && j <= 0)
		{
			revrotate_pswap(a, b, 'a');
			i--;
		}
		else if (i <= 0 && j > 0)
		{
			revrotate_pswap(b, a, 'b');
			j--;
		}
	}
}
