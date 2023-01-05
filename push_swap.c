/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:44:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/05 16:56:40 by jaiveca-         ###   ########.fr       */
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

void	print_stack(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		ft_printf("%i\n", temp->content);
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

/* INSTRUCTIONS */

void	swap_pswap(t_list **a, t_list **b, char c)
{
	int	temp;

	if (*a && (*a)->next)
	{
		temp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = temp;
	}
	if (*b && (*b)->next && c == 's')
	{
		temp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = temp;
	}
	ft_printf("s%c\n", c);
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

void	rotate_pswap(t_list **a, t_list **b, char c)
{
	if (*a)
	{
		ft_lstadd_back(a, ft_lstnew((*a)->content));
		*a = (*a)->next;
	}
	if (*b && c == 'r')
	{
		ft_lstadd_back(b, ft_lstnew((*b)->content));
		*b = (*b)->next;
	}
	ft_printf("r%c\n", c);
}

void	revrotate_pswap(t_list **a, t_list **b, char c)
{
	if (*a)
	{
		ft_lstadd_front(a, ft_lstnew(ft_lstlast(*a)->content));
		dellast_pswap(*a);
	}
	if (*b && c == 'r')
	{
		ft_lstadd_front(b, ft_lstnew(ft_lstlast(*b)->content));
		dellast_pswap(*b);
	}
	ft_printf("rr%c\n", c);
}

/* ALGORITHMS */

void sort_2_pswap(t_list **a, t_list **b)
{
	swap_pswap(a, b, 'a');
}

void sort_3_pswap(t_list **a, t_list **b)
{
	if ((*a)->content > (*a)->next->content)
		swap_pswap(a, b, 'a');
	if ((*a)->next->content > (*a)->next->next->content)
		swap_pswap(a, b, 'a');
}

void sort_pswap(t_list **a, t_list **b)
{
	int i;
	t_list	*temp;

	i = 0;
	temp = *a;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	if (i == 2)
		sort_2_pswap(a, b);
	else if (i == 3)
		sort_3_pswap(a, b);
}


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
	t_list	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		if (temp->content == curr)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int n;
	int i;
	t_list *a;
	t_list *b;

	a = NULL;
	b = NULL;
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
		ft_printf("Before\n");
		print_stack(&a);
		sort_pswap(&a, &b);
		ft_printf("After\n");
		print_stack(&a);
	}
	return (0);
}
