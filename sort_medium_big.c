/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:04 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/11 03:59:53 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	sort_big_pswap(t_list **a, t_list **b)
{
	if (check_if_sorted(a) == 0)
	{
		while (*a)
		{
			min_to_head(a, b);
			push_pswap(a, b, 'b');
		}
		while (*b)
		{
			push_pswap(b, a, 'a');
		}
	}
}*/

/*int	min2_int_node(t_list **a)
{
	t_list	*temp;
	int		min;
	int		min2;

	temp = *a;
	min = min_int_node(a);
	min2 = temp->content;
	while (temp)
	{
		if (temp->content != min && temp->content < min2)
			min2 = temp->content;
		temp = temp->next;
	}
	return (min2);
}

void	min_pair_index(t_list **a, t_list **b, t_mins *mins)
{	
	t_list	*temp;

	temp = *a;
	mins->min = min_int_node(a);
	mins->min2 = min2_int_node(a);
	mins->i_min = 0;
	mins->i_min2 = 0;
	while (temp->content != mins->min)
	{
		mins->i_min++;
		temp = temp->next;
	}
	temp = *a;
	while (temp->content != mins->min2)
	{
		mins->i_min2++;
		temp = temp->next;
	}
	min_pair_to_head(a, b, mins);
}

void	min_pair_to_head(t_list **a, t_list **b, t_mins *mins)
{
	int	midpoint;
	int	distance_min;
	int	distance_min2;
	int	i;

	midpoint = ft_lstsize(a) / 2;
	i = 0;
	if (mins->i_min < midpoint)
		distance_min = mins->i_min;
	else
		distance_min = ft_lstsize(a) - mins->i_min;
	if (mins->i_min2 < midpoint)
		distance_min2 = mins->i_min2;
	else
		distance_min2 = ft_lstsize(a) - mins->i_min2;
	if (distance_min < distance_min2)
	{
		while ((*a)->content != mins->min)
		{
			if (mins->i_min < midpoint)
				rotate_pswap(a, b, 'a');
			else
				revrotate_pswap(a, b, 'a');
		}
	}
	else
	{		
		while ((*a)->content != mins->min2)
		{
			if (mins->i_min2 < midpoint)
				rotate_pswap(a, b, 'a');
			else
				revrotate_pswap(a, b, 'a');
		}
	}
}

void	sort_big_pswap(t_list **a, t_list **b)
{
	t_mins	*mins;

	if (check_if_sorted(a) == 0)
	{
		while ((*a)->next->next)
		{
			mins = malloc(sizeof(t_mins));
			min_pair_index(a, b, mins);
			free(mins);
			push_pswap(a, b, 'b');
			min_to_head(a, b);
			push_pswap(a, b, 'b');
			if ((*b)->content < (*b)->next->content)
			{
				if ((*a)->content < (*a)->next->content)
					swap_pswap(a, b, 's');
				else
					swap_pswap(b, a, 'b');
			}
		}
		swap_pswap(a, b, 'a');
		while (*b)
		{
			push_pswap(b, a, 'a');
		}
	}
}*/

void	arg_indexer(t_list **a)
{
	t_list	*temp;
	t_list	*temp_head;

	temp = *a;
	temp_head = *a;
	while (*a)
	{
		while (temp)
		{
			if ((*a)->content > temp->content)
				(*a)->index++;
			temp = temp->next;
		}
		temp = temp_head;
		*a = (*a)->next;
	}
	*a = temp_head;
}

void	sort_big_pswap(t_list **a, t_list **b)
{

	arg_indexer(a);
	if (check_if_sorted(a) == 1)
	{
		while (*a)
		{
			min_to_head(a, b);
			push_pswap(a, b, 'b');
		}
		while (*b)
		{
			push_pswap(b, a, 'a');
		}
	}
}
