/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:24:22 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 16:30:10 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	go_to_val_in_b(t_stack **a, t_stack **b, int goal)
{
	if (!(*b) || !((*b)->next))
		return ;
	else if ((*b)->modulo - goal <= 5 && (*b)->modulo - goal >= -5)
	{
	while (!((*b)->modulo == goal && (*b)->prev->modulo != goal))
		choose_op(a, b, "rrb");
	}
	else
	{
		while (!((*b)->modulo == (*a)->modulo && (*b)->prev->modulo != goal))
			choose_op(a, b, "rb");
	}
}

static void	go_to_val_out_b(t_stack **a, t_stack **b, int min, int max)
{
	if ((*a)->modulo > max || (*a)->modulo < min)
	{
		go_to_val_in_b(a, b, max);
	}
	else if ((*b)->modulo - (*a)->modulo <= 5 && (*b)->modulo - (*a)->modulo >= -5)
	{
		while (!((*b)->modulo < (*a)->modulo
				&& (*b)->prev->modulo > (*a)->modulo))
			choose_op(a, b, "rrb");
	}
	else
	{
		while (!((*b)->modulo < (*a)->modulo
				&& (*b)->prev->modulo > (*a)->modulo))
			choose_op(a, b, "rb");
	}
}

void	radix_sort_tob(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	if (is_sorted(stack_a) <= 1)
	{
		finish(stack_a, stack_b);
		return ;
	}
	while (*stack_a)
	{
		if (in_stack(stack_b, (*stack_a)->modulo))
			go_to_val_in_b(stack_a, stack_b, (*stack_a)->modulo);
		else
			go_to_val_out_b(stack_a, stack_b, min, max);
		choose_op(stack_a, stack_b, "pb");
		if ((*stack_b)->modulo > max)
			max = (*stack_b)->modulo;
		if ((*stack_b)->modulo < min)
			min = (*stack_b)->modulo;
	}
	update_stack(stack_b);
	radix_sort_toa(stack_a, stack_b, 9, 0);
}
