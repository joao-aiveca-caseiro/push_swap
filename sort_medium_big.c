/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:04 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/11 20:06:41 by jaiveca-         ###   ########.fr       */
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

int	chunk_int_node(t_list **a, int chunk_top)
{
	t_list	*temp;
	int		pos_top;
	int		pos_bottom;
	int		selected_pos;

	temp = *a;
	pos_top = 0;
	pos_bottom = ft_lstsize(a);
	selected_pos = 0;
	while (temp && (temp->index > chunk_top || temp->index < chunk_top - 10))
	{
		pos_top++;
		temp = temp->next;
	}
	while (temp && (temp->index > chunk_top || temp->index < chunk_top - 10))
	{
		pos_bottom--;
		ft_lstadd_front(&temp, ft_lstnew(ft_lstlast(temp)->content, ft_lstlast(temp)->index));
		dellast_pswap(temp);
	}
	ft_printf("chunk_top is %i and chunk_bottom is %i\n", chunk_top, chunk_top - 10);
	ft_printf("pos_top is %i and pos_bottom is %i\n", pos_top, pos_bottom);
	ft_printf("list size is %i\n", ft_lstsize(a));
	if (ft_lstsize(a) - pos_bottom >= 0 && ft_lstsize(a) - pos_bottom < pos_top)
		selected_pos = pos_bottom;
	else
		selected_pos = pos_top;
	ft_printf("selected_pos is %i\n", selected_pos);
	return (selected_pos);
}

void	selected_to_head(t_list **a, t_list **b, int chunk_top)
{	
	t_list	*temp;
	int		i;
	int		selected_pos;
	int		selected_index;

	temp = *a;
	if (ft_lstsize(a) > 1)
	{
		selected_pos = chunk_int_node(a, chunk_top);
		i = 0;
		while (i < selected_pos - 1)
		{
			i++;
			temp = temp->next;
		}
		selected_index = temp->index;
		ft_printf("selected_index is %i\n", selected_index);
		while ((*a)->index != selected_index)
		{
			if (i < ft_lstsize(a) / 2)
				rotate_pswap(a, b, 'a');
			else
				revrotate_pswap(a, b, 'a');
		}
	}
}

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

int	rot_b_before_push(t_list **a, t_list **b)
{
	t_list	*temp;
	int		check;

	temp = *b;
	check = 0;
	while (temp)
	{
		if ((*a)->index > temp->index)
			check = 1;
		temp = temp->next;
	}
	return (check);
}

void	sort_big_pswap(t_list **a, t_list **b)
{
	int	init_lstsize;
	int	i;
	int	j;

	init_lstsize = ft_lstsize(a);
	i = 0;
	j = 1;
	arg_indexer(a);
	ft_printf("Before\n");
	print_stack(a);
	if (check_if_sorted(a) == 0)
	{
		while (*a)
		{
			while ((*a) && i < 10 * j)
			{
				/*selected_to_head(a, b, 10 * j);
				if (rot_b_before_push(a, b) == 1)
					while ((*a)->index < (*b)->index)
						rotate_pswap(b, a, 'b');*/
				push_pswap(a, b, 'b');
				i++;
				//print_stack(a);
			}
			j++;
		}
		while (*b)
		{
			push_pswap(b, a, 'a');
		}
		while ((*a)->index != 0)
		{
			revrotate_pswap(a, b, 'a');
		}
	}
}
