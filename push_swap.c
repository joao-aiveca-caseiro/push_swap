/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:44:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/03 18:07:48 by jaiveca-         ###   ########.fr       */
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

/*

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
*/

/* MAIN STUFF */

int	check_int_pswap(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		i++;
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		check = 1;
//	ft_printf("%i\n", check);
	return (check);
}

long	atoi_pswap(char *str)
{
	int		i;
	long	nb;
	long	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb = nb + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

int	check_doubles_pswap(t_list **stack, int curr)
{
	while (*stack)
	{
		if ((*stack)->content == curr)
			return (0);
		*stack = (*stack)->next;
	}
	return (1);
}

void print_stack(t_list **a)
{
	while (*a != NULL)
	{
		ft_printf("%i\n", (*a)->content);
		*a = (*a)->next;
	}
}

int	main(int argc, char **argv)
{
	int n;
	int i;
	t_list *a;
//	t_list *b;

	a = NULL;
//	b = NULL;
	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (check_int_pswap(argv[i]) == 1)
			{
				n = atoi_pswap(argv[i]);
				if (n >= INT_MIN && n <= INT_MAX && check_doubles_pswap(&a, n) == 1)
					ft_lstadd_back(&a, ft_lstnew(n));
				else
					write (2, "Error\n", 6);
			}
			else
			{
				write (2, "Error\n", 6);
				break ;
			}
			i++;
		}
	}
	ft_printf("Stack A\n");
	print_stack(&a);
	return (0);
}

/*int	main(void)
{
	t_list	*stack_a;
//	t_list	*teste2 = ft_lstnew(2);
//	t_list	*teste3 = ft_lstnew(3);
//	t_list	*teste4 = ft_lstnew(4);

	stack_a = NULL;

	ft_lstadd_back(&stack_a, ft_lstnew(2));
	ft_lstadd_back(&stack_a, ft_lstnew(3));
	ft_lstadd_back(&stack_a, ft_lstnew(4));

	t_list *stack_b = NULL;

	//swap_pswap(&stack_a, 'a');
	//push_pswap(&stack_a, &stack_b, 'b');
	//revrotate_pswap(&stack_a, 'a');

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
}*/
