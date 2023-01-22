/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:34:58 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 18:12:10 by jaiveca-         ###   ########.fr       */
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

t_list	*lstcpy_pswap(t_list *source)
{
	t_list	*head;
	t_list	*node;

	if (source == NULL)
		return (NULL);
	head = malloc(sizeof(t_list));
	head->content = source->content;
	head->index = source->index;
	source = source->next;
	node = head;
	while (source)
	{
		node->next = malloc(sizeof(t_list));
		node = node->next;
		node->content = source->content;
		node->index = source->index;
		source = source->next;
	}
	node->next = NULL;
	return (head);
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
