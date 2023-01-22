/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 18:10:57 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 18:12:19 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_int_node(t_list **a)
{
	t_list	*temp;
	int		min;

	temp = *a;
	min = temp->content;
	while (temp)
	{
		if (temp->content < min)
			min = temp->content;
		temp = temp->next;
	}
	return (min);
}

void	min_to_head(t_list **a, t_list **b)
{	
	t_list	*temp;
	int		min;
	int		i;

	temp = *a;
	min = min_int_node(a);
	i = 0;
	while (temp->content != min)
	{
		i++;
		temp = temp->next;
	}
	while ((*a)->content != min)
	{
		if (i < ft_lstsize(a) / 2)
			rotate_pswap(a, b, 'a');
		else
			revrotate_pswap(a, b, 'a');
	}
}
