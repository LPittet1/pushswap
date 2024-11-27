/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:30:51 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 16:31:03 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	choose_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	if (!is_sorted(stack_a))
		return ;
	if (size == 2)
		choose_op(stack_a, stack_b, "sa");
	else if (size == 3)
		sort_3(stack_a, stack_b);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
	{
		get_final_index(stack_a, size);
		radix_sort_tob(stack_a, stack_b, 9, 0);
	}
}

char	*best_op(t_stack **stack, t_stack *head, size_t i)
{
	while (1)
	{
		if ((*stack)->content > (*stack)->next->content)
		{
			while ((*stack)->content > (*stack)->next->content)
			{
				*stack = (*stack)->next;
				i++;
			}
		}
		else
		{
			while ((*stack)->content < (*stack)->next->content)
			{
				*stack = (*stack)->next;
				i++;
			}
		}
		*stack = (*stack)->next;
		if (*stack == head)
			break ;
	}
	if (i > dblist_size(stack) / 2)
		return ("rr");
	return ("r");
}

void	finish(t_stack **a, t_stack **b)
{
	// char *op;
	
	if (!*a)
	{
		if (!is_sorted_reverse(b))
		{
			// op = best_op(b, *b, 0);
			// ft_printf("op = %s\n", op);
			while (is_sorted_reverse(b))
				choose_op(a, b, "rb");
			while (*b)
				choose_op(a, b, "pa");
		}
	}
	else if (!*b)
	{
		// op = best_op(a, *a, 0);
		// ft_strlcat(op, "a", 4);
		// ft_printf("op = %s\n", "ra");
		while (is_sorted(a))
			choose_op(a, b, "ra");
	}
}
