/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:57:30 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/28 14:16:29 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	go_to_val_in_a(t_stack **a, t_stack **b, int goal)
{
	int	dir;
	int	i;

	dir = 0;
	i = 0;
	if (!(*a) || !((*a)->next))
		return ;
	while (i < 5)
	{
		if (((*b)->modulo + 10 - i) == goal)
			dir = 1;
		i++;
	}
	if (!dir)
	{
		while (!((*a)->modulo == goal && (*a)->prev->modulo != goal))
			choose_op(a, b, "rra");
	}
	else
	{
		while (!((*a)->modulo == goal && (*a)->prev->modulo != goal))
			choose_op(a, b, "ra");
	}
}

static void	go_to_val_out_a(t_stack **a, t_stack **b, int min, int max)
{
	int	dir;
	int	i;

	dir = 0;
	i = 0;
	if ((*b)->modulo > max || (*b)->modulo < min)
		return (go_to_val_in_a(a, b, min));
	while (i < 5)
	{
		if (((*b)->modulo + 10 - i) == (*b)->modulo)
			dir = 1;
		i++;
	}
	if (dir)
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

void	radix_sort_toa(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
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
			go_to_val_out_a(stack_a, stack_b, min, max);
		choose_op(stack_a, stack_b, "pa");
		if ((*stack_a)->modulo > max)
			max = (*stack_a)->modulo;
		if ((*stack_a)->modulo < min)
			min = (*stack_a)->modulo;
	}
	update_stack(stack_a);
	radix_sort_tob(stack_a, stack_b, 9, 0);
}
