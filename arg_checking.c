/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:48:41 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/09 18:52:13 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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