/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:18 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/20 19:25:33 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_pswap(t_list **a, t_list **b, char c)
{
	int	temp;

	if (*a && (*a)->next)
	{
		temp = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = temp;
		temp = (*a)->index;
		(*a)->index = (*a)->next->index;
		(*a)->next->index = temp;
	}
	if (*b && (*b)->next && c == 's')
	{
		temp = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = temp;
		temp = (*b)->index;
		(*b)->index = (*b)->next->index;
		(*b)->next->index = temp;
	}
	ft_printf("s%c\n", c);
}

void	push_pswap(t_list **src, t_list **dest, char c)
{
	t_list	*temp;

	if (*src)
	{
		ft_lstadd_front(dest, ft_lstnew((*src)->content, (*src)->index));
		temp = *src;
		*src = (*src)->next;
		ft_lstdelone(temp, NULL);
		ft_printf("p%c\n", c);
	}
}

void	rotate_pswap(t_list **a, t_list **b, char c)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (*a)
	{
		ft_lstadd_back(a, ft_lstnew((*a)->content, (*a)->index));
		temp_a = *a;
		*a = (*a)->next;
		ft_lstdelone(temp_a, NULL);
	}
	if (*b && c == 'r')
	{
		ft_lstadd_back(b, ft_lstnew((*b)->content, (*b)->index));
		temp_b = *b;
		*b = (*b)->next;
		ft_lstdelone(temp_b, NULL);
	}
	ft_printf("r%c\n", c);
}

void	revrotate_pswap(t_list **a, t_list **b, char c)
{
	if (*a)
	{
		ft_lstadd_front(a, ft_lstnew(ft_lstlast(*a)->content, ft_lstlast(*a)->index));
		dellast_pswap(*a);
	}
	if (*b && c == 'r')
	{
		ft_lstadd_front(b, ft_lstnew(ft_lstlast(*b)->content, ft_lstlast(*b)->index));
		dellast_pswap(*b);
	}
	ft_printf("rr%c\n", c);
}