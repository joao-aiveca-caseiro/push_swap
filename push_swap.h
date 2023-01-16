/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:23:03 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/16 16:45:46 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_mins
{
	int				min;
	int				min2;
	int				i_min;
	int				i_min2;
}				t_mins;

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
void	min_pair_index(t_list **a, t_list **b, t_mins *mins);
void	min_pair_to_head(t_list **a, t_list **b, t_mins *mins);
int		min2_int_node(t_list **a);
void	to_top(t_list **a, t_list **b, int selected_index);
void	arg_indexer(t_list **a);

#endif