/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:44:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2022/12/12 16:58:04 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(void)
{
	t_list	*stack_a = ft_lstnew((void *) 1);
	t_list	*teste2 = ft_lstnew((void *) 2);
	t_list	*teste3 = ft_lstnew((void *)3);
	t_list	*teste4 = ft_lstnew((void *)4);

	ft_lstadd_back(&stack_a, teste2);
	ft_lstadd_back(&stack_a, teste3);
	ft_lstadd_back(&stack_a, teste4);

	while (stack_a != NULL)
	{
		ft_printf("%i\n", stack_a->content);
		stack_a = stack_a->next;
	}

//	ft_lstiter(stacka, (void *)function);
//	ft_printf("%i", stacka->content);
}
