/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:03:18 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/29 13:35:48 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(stack_a))
		return ;
	if ((*stack_a)->prev->content > (*stack_a)->content
		&& (*stack_a)->prev->content < (*stack_a)->next->content)
	{
		choose_op(stack_a, stack_b, "sa");
		choose_op(stack_a, stack_b, "ra");
	}
	else if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->prev->content)
		choose_op(stack_a, stack_b, "sa");
	else if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->prev->content)
		choose_op(stack_a, stack_b, "rra");
	else if ((*stack_a)->next->content < (*stack_a)->content
		&& (*stack_a)->next->content > (*stack_a)->prev->content)
	{
		choose_op(stack_a, stack_b, "sa");
		choose_op(stack_a, stack_b, "rra");
	}
	else
		choose_op(stack_a, stack_b, "ra");
}

void	insert_sort(t_stack **a, t_stack **b)
{
	int	min;

	while (dblist_size(a) != 3)
	{
		min = find_min(a, INT_MIN);
		if (!is_sorted(a))
			break ;
		goto_val_a(a, b, min);
		choose_op(a, b, "pb");
	}
	sort_3(a, b);
	while (*b)
		choose_op(a, b, "pa");
}
