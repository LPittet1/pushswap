/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:35:36 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 16:30:43 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft1/includes/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				content;
	unsigned int	index;
	int				modulo;
	struct s_stack	*next;
}	t_stack;

// parser.c
t_stack	*parser(char **av);

// utils.c
int		is_sorted(t_stack **stack);
int		is_sorted_reverse(t_stack **stack);
void	goto_val_a(t_stack **stack_a, t_stack **stack_b, int goal);
void	print_stack(t_stack *stack);
void	choose_op(t_stack **stack_a, t_stack **stack_b, char *op);

// dblst.c
t_stack	*dblstnew(int content);
t_stack	*dblstadd_back(t_stack *head, int content);
t_stack	*dblstadd_front(t_stack *head, int content);
void	dblstdelete(t_stack *head);
size_t	dblist_size(t_stack **stack);

// operations.c
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	push(t_stack **stack_1, t_stack **stack_2);

// utils_2.c
void	choose_sort(t_stack **stack_a, t_stack **stack_b, size_t size);
void	finish(t_stack **a, t_stack **b);

// minisort.c
void	sort_3(t_stack **stack_a, t_stack **stack_b);
void	sort_4(t_stack **stack_a, t_stack **stack_b);
void	sort_5(t_stack **stack_a, t_stack **stack_b);

// radix_utils.c
void	get_final_index(t_stack **stack, size_t size);
int		find_min(t_stack **stack, int last);
int		in_stack(t_stack **stack, int modulo);
void	update_stack(t_stack **stack);

// radix_2.c
void	radix_sort_toa(t_stack **stack_a, t_stack **stack_b, int min, int max);

// radix.c
void	radix_sort_tob(t_stack **stack_a, t_stack **stack_b, int min, int max);

#endif