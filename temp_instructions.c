/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:18 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/19 19:10:19 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
"Codes" passed to the instructions list:
	pa - 1 
	pb - 2
	ra - 3
	rb - 4
	rra - 5
	rrb - 6
*/

void	temp_push_pswap(t_list **src, t_list **dest, char c, t_list **instr)
{
	if (*src)
	{
		ft_lstadd_front(dest, ft_lstnew((*src)->content, (*src)->index));
		*src = (*src)->next;
	}
	if (c == 'a')
		temp_lstadd_back(instr, ft_lstnew(1, 0));
	if (c == 'b')
		temp_lstadd_back(instr, ft_lstnew(2, 0));
}

void	temp_rotate_pswap(t_list **a, t_list **b, char c, t_list **instr)
{
	if (*a)
	{
		ft_lstadd_back(a, ft_lstnew((*a)->content, (*a)->index));
		*a = (*a)->next;
	}
	if (*b && c == 'r')
	{
		ft_lstadd_back(b, ft_lstnew((*b)->content, (*b)->index));
		*b = (*b)->next;
	}
	if (c == 'a')
		temp_lstadd_back(instr, ft_lstnew(3, 0));
	if (c == 'b')
		temp_lstadd_back(instr, ft_lstnew(4, 0));
}

void	temp_revrotate_pswap(t_list **a, t_list **b, char c, t_list **instr)
{
	if (*a)
	{
		ft_lstadd_front(a, \
		ft_lstnew(ft_lstlast(*a)->content, ft_lstlast(*a)->index));
		dellast_pswap(*a);
	}
	if (*b && c == 'r')
	{
		ft_lstadd_front(b, \
		ft_lstnew(ft_lstlast(*b)->content, ft_lstlast(*b)->index));
		dellast_pswap(*b);
	}
	if (c == 'a')
		temp_lstadd_back(instr, ft_lstnew(5, 0));
	if (c == 'b')
		temp_lstadd_back(instr, ft_lstnew(6, 0));
}

void	temp_min_to_head(t_list **a, t_list **b, t_list **instr)
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
			temp_rotate_pswap(a, b, 'a', instr);
		else
			temp_revrotate_pswap(a, b, 'a', instr);
	}
}

void	temp_to_top(t_list **a, t_list **b, int selected_index, t_list **instr)
{	
	t_list	*temp;
	int		i;

	temp = *b;
	i = 0;
	while (temp->index != selected_index)
	{
		i++;
		temp = temp->next;
	}
	while ((*b)->index != selected_index)
	{
		if (i < ft_lstsize(b) / 2)
			temp_rotate_pswap(b, a, 'b', instr);
		else
			temp_revrotate_pswap(b, a, 'b', instr);
	}
}
