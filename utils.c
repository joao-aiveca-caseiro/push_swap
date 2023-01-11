/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:34:58 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/11 15:51:46 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dellast_pswap(t_list *node)
{
	if (node)
	{
		while (node->next->next)
			node = node->next;
		free(node->next);
		node->next = NULL;
	}
}

void	print_stack(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		printf("%8i", temp->content);
		printf("       ---");
		printf("%8i\n", temp->index);
		temp = temp->next;
	}
}

int	check_if_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

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
