/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:30 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 15:43:54 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	go_to_val_in_a(t_stack **a, t_stack **b, int goal)
{
	if (!(*a) || !((*a)->next))
		return ;
	else if ((*a)->modulo - goal <= 5 )
	{
		while (!((*a)->modulo == goal
				&& (*a)->prev->modulo != goal))
			choose_op(a, b, "rra");
	}
	else
	{
		while (!((*a)->modulo == goal
				&& (*a)->prev->modulo != goal))
			choose_op(a, b, "ra");
	}
}

static void	go_to_val_out_a(t_stack **a, t_stack **b, int min, int max)
{
	if ((*b)->modulo > max || (*b)->modulo < min)
		go_to_val_in_a(a, b, min);
	else if (abs((*a)->modulo - (*b)->modulo) <= 5)
	{
		while (!((*a)->modulo > (*b)->modulo
				&& (*a)->prev->modulo < (*b)->modulo))
			choose_op(a, b, "rra");
	}
	else
	{
		while (!((*a)->modulo > (*b)->modulo
				&& (*a)->prev->modulo < (*b)->modulo))
			choose_op(a, b, "ra");
	}
}

void	radix_sort_toa(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	max;

	min = 9;
	max = 0;
	if (is_sorted_reverse(stack_b) <= 1)
	{
		finish(stack_a, stack_b);
		return ;
	}
	while (*stack_b)
	{
		if (in_stack(stack_a, (*stack_b)->modulo))
			go_to_val_in_a(stack_a, stack_b, (*stack_b)->modulo);
		else
		{
			go_to_val_out_a(stack_a, stack_b, min, max);
		}
		choose_op(stack_a, stack_b, "pa");
		if ((*stack_a)->modulo > max)
			max = (*stack_a)->modulo;
		if ((*stack_a)->modulo < min)
			min = (*stack_a)->modulo;
	}
	update_stack(stack_a);
	radix_sort_tob(stack_a, stack_b);
}
