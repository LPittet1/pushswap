/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:35:36 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/21 09:05:23 by lpittet          ###   ########.fr       */
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
	ssize_t			size;
	char			name;
	struct s_stack	*next;
}	t_stack;

typedef	struct s_ab
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		a_size;
	int		b_size;
}	t_ab;

// parser.c
t_stack	*parser(char **av);

// utils.c
int	is_sorted(t_stack **stack);

// dblst.c
t_stack	*dblstnew(int content);
t_stack	*dblstadd_back(t_stack *head, int content);
t_stack	*dblstadd_front(t_stack *head, int content);
void	dblstdelete(t_stack *head);
size_t	dblist_size(t_stack **stack);

// operations.c
void 	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	rev_rotate(t_stack **stack);
void	push(t_stack **stack_1, t_stack **stack_2);

// sorting_test
void	bubble_sort(t_stack **stack);

#endif