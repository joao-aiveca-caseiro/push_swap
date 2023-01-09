/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_big.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:35:04 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/09 18:47:19 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big_pswap(t_list **a, t_list **b)
{
	if (check_if_sorted(a) == 0)
	{
		while (*a)
		{
			min_to_head(a, b);
			push_pswap(a, b, 'b');
		}
		while (*b)
		{
			push_pswap(b, a, 'a');
		}
	}
}