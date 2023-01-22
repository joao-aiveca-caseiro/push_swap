/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:44:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 18:33:40 by jaiveca-         ###   ########.fr       */
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
	ft_lstclear(&temp_a);
}

int	arg_checking_pswap(char *arg, t_list **a)
{
	long	n;
	int		check;

	check = 0;
	n = atoi_pswap(arg);
	if (check_int_pswap(arg) == 1)
		check++;
	if (n >= INT_MIN && n <= INT_MAX)
		check++;
	if (check_doubles_pswap(a, n) == 1)
		check++;
	return (check);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*b;
	t_list	*instr;

	a = NULL;
	b = NULL;
	instr = NULL;
	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (arg_checking_pswap(argv[i], &a) == 3)
				ft_lstadd_back(&a, ft_lstnew(atoi_pswap(argv[i]), 0));
			else
				input_error_pswap();
			i++;
		}
		sort_pswap(&a, &b, &instr);
	}
}
