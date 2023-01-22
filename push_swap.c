/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:44:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 05:39:22 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pswap(t_list **a, t_list **b, t_list **instr)
{
	int		i;
	t_list	*temp_a;
	t_list	*temp_b;

	i = ft_lstsize(a);
	temp_a = lstcpy_pswap(*a);
	temp_b = NULL;
	if (i == 2)
		sort_2_pswap(a, b);
	else if (i == 3)
		sort_3_pswap(a, b);
	else if (i <= 5)
		sort_upto5_pswap(a, b);
	else if (i > 5)
	{
		sort_big_pswap(&temp_a, &temp_b, instr);
		optimizer_pswap(a, b, instr);
	}
	ft_lstclear(a);
	ft_lstclear(b);
}

int	main(int argc, char **argv)
{
	int		n;
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*instr;

	a = NULL;
	b = NULL;
	instr = NULL;
	i = 1;
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (check_int_pswap(argv[i]) == 1)
			{
				n = atoi_pswap(argv[i]);
				if (n >= INT_MIN && n <= INT_MAX && check_doubles_pswap(&a, n) == 1)
					ft_lstadd_back(&a, ft_lstnew(n, 0));
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
		sort_pswap(&a, &b, &instr);
	}
	return (0);
}
