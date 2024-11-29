/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:35:36 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/29 13:37:47 by lpittet          ###   ########.fr       */
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

// dblist.c
t_stack	*dblstnew(int content);
t_stack	*dblstadd_back(t_stack *head, int content);
t_stack	*dblstadd_front(t_stack *head, int content);
void	dblstdelete(t_stack *head);
size_t	dblist_size(t_stack **stack);

// insert.c
void	sort_3(t_stack **stack_a, t_stack **stack_b);
void	insert_sort(t_stack **a, t_stack **b);

// operations.c
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	push(t_stack **stack_1, t_stack **stack_2);

// parser.c
t_stack	*parser(char **av);

// radix_bin.c
void	radix_bin(t_stack **a, t_stack **b, size_t msb);

// radix_utils.c
void	get_final_index(t_stack **stack, size_t size);
int		get_msb(size_t size);

// utils.c
int		is_sorted(t_stack **stack);
void	goto_val_a(t_stack **stack_a, t_stack **stack_b, int goal);
void	choose_op(t_stack **stack_a, t_stack **stack_b, char *op);
int		find_min(t_stack **stack, int last);
void	choose_sort(t_stack **stack_a, t_stack **stack_b, size_t size);

#endif