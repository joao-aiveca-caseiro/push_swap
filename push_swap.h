/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:23:03 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/09 19:04:55 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

void	sort_pswap(t_list **a, t_list **b);
int		check_int_pswap(char *str);
long	atoi_pswap(char *str);
int		check_doubles_pswap(t_list **stack, int curr);
void	swap_pswap(t_list **a, t_list **b, char c);
void	push_pswap(t_list **src, t_list **dest, char c);
void	rotate_pswap(t_list **a, t_list **b, char c);
void	revrotate_pswap(t_list **a, t_list **b, char c);
void	sort_big_pswap(t_list **a, t_list **b);
void	sort_2_pswap(t_list **a, t_list **b);
void	sort_3_pswap(t_list **a, t_list **b);
void	sort_upto5_pswap(t_list **a, t_list **b);
void	dellast_pswap(t_list *node);
void	print_stack(t_list **stack);
int		check_if_sorted(t_list **stack);
int		min_int_node(t_list **a);
void	min_to_head(t_list **a, t_list **b);

#endif