/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:24:22 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/26 14:23:31 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	go_to_val_in_b(t_stack **a, t_stack **b)
{
	if ((*b)->modulo - (*a)->modulo <= abs(5))
	{
		while (!((*b)->modulo == (*a)->modulo
				&& (*b)->prev->modulo) != (*a)->modulo)
			choose_op(a, b, "rrb");
	}
	else
	{
		while (!((*b)->modulo == (*a)->modulo
				&& (*b)->prev->modulo) != (*a)->modulo)
			choose_op(a, b, "rb");
	}
}

void	go_to_val_out_b(t_stack **a, t_stack **b)
{
	if ((*b)->modulo - (*a)->modulo <= abs(5))
	{
		while (*a)
			choose_op(a, b, "rrb");
	}
	else
	{
		while (*a)
			choose_op(a, b, "rb");
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int min;
	int max;
	
	min = 9;
	max = 0;
	if (is_sorted(stack_a))
		return ;
	while (*stack_a)
	{
		if (in_stack(stack_b, (*stack_a)->modulo))
			go_to_val_in_b(stack_a, stack_b);
		else
		{
			go_to_val_out_b(stack_a, stack_b);
		}
		choose_op(stack_a, stack_b, "pb");
		if ((*stack_b)->modulo > max)
			max = (*stack_b)->modulo;
		if ((*stack_b)->modulo < min)
			min = (*stack_b)->modulo;
	}
	update_stack(stack_b);
	radix_sort_back(stack_a, stack_b);
}
