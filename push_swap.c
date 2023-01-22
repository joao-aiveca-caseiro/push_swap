/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:44:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/22 14:19:51 by jaiveca-         ###   ########.fr       */
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

int	arg_checking_pswap(char *arg, t_list **a)
{
	int	n;

	if (check_int_pswap(arg) == 0)
		return (0);
	n = atoi_pswap(arg);
	if (n < INT_MIN && n > INT_MAX)
		return (0);
	if (check_doubles_pswap(a, n) == 0)
		return (0);
	return (1);
}

void	input_error_pswap(void)
{
	write(2, "Error\n", 6);
	exit (0);
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
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (arg_checking_pswap(argv[i], &a) == 1)
				ft_lstadd_back(&a, ft_lstnew(atoi_pswap(argv[i]), 0));
			else
				input_error_pswap();
			i++;
		}
		ft_printf("%i\n", i);
		sort_pswap(&a, &b, &instr);
	}
	else
		input_error_pswap();
	return (0);
}

/*int	main(int argc, char **argv)
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
}*/
