/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:31:59 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/21 04:50:07 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimizer_pswap(t_list **a, t_list **b, t_list **instr)
{
	while (*instr)
	{
		if ((*instr)->content == 2 && (*instr)->next && (*instr)->next->content == 1)
			(*instr) = (*instr)->next;
		else if ((*instr)->content == 1)
			push_pswap(b, a, 'a');
		else if ((*instr)->content == 2)
			push_pswap(a, b, 'b');
		else if ((*instr)->content == 4)
			rotate_pswap(b, a, 'b');
		else if ((*instr)->content == 6)
			revrotate_pswap(b, a, 'b');
		else if ((*instr)->content == 3)
			rotate_optimizer_pswap(a, b, instr);
		else if ((*instr)->content == 5)
			revrotate_optimizer_pswap(a, b, instr);
		*instr = (*instr)->next;
	}
}

void	rotate_optimizer_pswap(t_list **a, t_list **b, t_list **instr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if ((*instr)->content == 3)
	{
		while ((*instr)->next && (*instr)->next->content == 3)
		{
			*instr = (*instr)->next;
			i++;
		}
		while ((*instr)->next && (*instr)->next->content == 4)
		{
			*instr = (*instr)->next;
			j++;
		}
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
}

void	revrotate_optimizer_pswap(t_list **a, t_list **b, t_list **instr)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if ((*instr)->content == 5)
	{
		while ((*instr)->next && (*instr)->next->content == 5)
		{
			*instr = (*instr)->next;
			i++;
		}
		while ((*instr)->next && (*instr)->next->content == 6)
		{
			*instr = (*instr)->next;
			j++;
		}
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
}
