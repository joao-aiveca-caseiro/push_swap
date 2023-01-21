/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 12:23:03 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/01/21 05:19:04 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

void	sort_pswap(t_list **a, t_list **b, t_list **instr);
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
void	to_top(t_list **a, t_list **b, int selected_index);
void	arg_indexer(t_list **a);

void	temp_push_pswap(t_list **src, t_list **dest, char c, t_list **instr);
void	temp_rotate_pswap(t_list **a, t_list **b, char c, t_list **instr);
void	temp_revrotate_pswap(t_list **a, t_list **b, char c, t_list **instr);
void	temp_min_to_head(t_list **a, t_list **b, t_list **instr);
void	temp_to_top(t_list **a, t_list **b, int selected_index, t_list **instr);
void	temp_sort_big_pswap(t_list **a, t_list **b, t_list **instr);
void	temp_selected_to_head(t_list **a, t_list **b, int chunk_top, int k, t_list **instr);
int		temp_chunk_int_node(t_list **a, int chunk_top, int k);
void	optimizer_pswap(t_list **a, t_list **b, t_list **instr);
void	rotate_optimizer_pswap(t_list **a, t_list **b, t_list **instr);
void	revrotate_optimizer_pswap(t_list **a, t_list **b, t_list **instr);
void	temp_lstadd_back(t_list **lst, t_list *new);
t_list	*lstcpy_pswap(t_list *source);
void	temp_lstclear_pswap(t_list *head);


#endif