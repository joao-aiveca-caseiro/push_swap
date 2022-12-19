/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:44:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/12/19 17:44:38 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* UTILS */

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

/* INSTRUCTIONS */

void	swap_pswap(t_list **stack, char c)
{
	void	*temp;

	if (*stack)
	{
		temp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
		ft_printf("s%c\n", c);
	}
}

void	push_pswap(t_list **src, t_list **dest, char c)
{
	if (*src)
	{
		ft_lstadd_front(dest, ft_lstnew((*src)->content));
		*src = (*src)->next;
		ft_printf("p%c\n", c);
	}
}

void	rotate_pswap(t_list **stack, char c)
{
	if (*stack)
	{
		ft_lstadd_back(stack, ft_lstnew((*stack)->content));
		*stack = (*stack)->next;
		ft_printf("r%c\n", c);
	}
}

void	revrotate_pswap(t_list **stack, char c)
{
	if (*stack)
	{
		ft_lstadd_front(stack, ft_lstnew(ft_lstlast(*stack)->content));
		dellast_pswap(*stack);
		ft_printf("r%c\n", c);
	}
}

/* ALGORITHMS */






int	main(void)
{
	t_list	*stack_a = ft_lstnew((void *) 1);
	t_list	*teste2 = ft_lstnew((void *) 2);
	t_list	*teste3 = ft_lstnew((void *)3);
	t_list	*teste4 = ft_lstnew((void *)4);

	ft_lstadd_back(&stack_a, teste2);
	ft_lstadd_back(&stack_a, teste3);
	ft_lstadd_back(&stack_a, teste4);

	t_list *stack_b = NULL;

	//swap_pswap(&stack_a, 'a');
	//push_pswap(&stack_a, &stack_b, 'b');
	revrotate_pswap(&stack_a, 'a');

	ft_printf("Stack A\n");
	while (stack_a != NULL)
	{
		ft_printf("%i\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_printf("Stack B\n");
	while (stack_b != NULL)
	{
		ft_printf("%i\n", stack_b->content);
		stack_b = stack_b->next;
	}

//	ft_lstiter(stacka, (void *)function);
//	ft_printf("%i", stacka->content);
}
