/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:30:51 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 20:12:00 by lpittet          ###   ########.fr       */
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

char	*best_op_b(t_stack **stack)
{
	size_t	i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while ((*stack)->content < (*stack)->prev->content)
	{
		i++;
		*stack = (*stack)->next;
	}
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		if (*stack == temp)
			break ;
	}
	if (i > dblist_size(stack) / 2)
		return ("rrb");
	return ("rb");
}

char	*best_op_a(t_stack **stack)
{
	size_t i;
	t_stack *temp;

	i = 0;
	temp = *stack;
	while ((*stack)->content > (*stack)->prev->content)
	{
		i++;
		*stack = (*stack)->next;
	}
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		if (*stack == temp)
			break ;
	}
	if (i > dblist_size(stack) / 2)
		return ("rra");
	return ("ra");
}

void	finish(t_stack **a, t_stack **b)
{
	char *op;
	
	if (!*a)
	{
		if (is_sorted_reverse(b))
		{
			op = best_op_b(b);
			while (is_sorted_reverse(b))
				choose_op(a, b, op);
		}
		while (*b)
				choose_op(a, b, "pa");
	}
	else if (!*b)
	{
		op = best_op_a(a);
		while (is_sorted(a))
			choose_op(a, b, op);
	}
}
