/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:30 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 10:14:59 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	go_to_val_in_a(t_stack **a, t_stack **b, int modulo)
{
	if (!(*a) || !((*a)->next))
		return ;
	else if (abs((*a)->modulo - modulo) <= 5)
	{
		while (!((*a)->modulo == modulo
				&& (*a)->prev->modulo != modulo))
			choose_op(a, b, "rra");
	}
	else
	{
		while (!((*a)->modulo == modulo
				&& (*a)->prev->modulo != modulo))
			choose_op(a, b, "ra");
	}
}

void	go_to_val_out_a(t_stack **a, t_stack **b, int min, int max)
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
