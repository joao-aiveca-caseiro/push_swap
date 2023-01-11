/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:44:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/11 19:17:50 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_pswap(t_list **a, t_list **b)
{
	int	i;

	i = ft_lstsize(a);
	if (i == 2)
		sort_2_pswap(a, b);
	else if (i == 3)
		sort_3_pswap(a, b);
	else if (i <= 5)
		sort_upto5_pswap(a, b);
	else if (i > 5)
		sort_big_pswap(a, b);
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
//		ft_printf("Before\n");
//		print_stack(&a);
		sort_pswap(&a, &b);
		ft_printf("\nAfter\n");
		print_stack(&a);
	}
	return (0);
}
