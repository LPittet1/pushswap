/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:51:02 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/22 16:07:02 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->prev->content > (*stack_a)->content &&
		(*stack_a)->prev->content < (*stack_a)->next->content)
	{
		choose_op(stack_a, stack_b, "sa");
		choose_op(stack_a, stack_b, "ra");
	}
	else if ((*stack_a)->content > (*stack_a)->next->content &&
		(*stack_a)->content < (*stack_a)->prev->content)
		choose_op(stack_a, stack_b, "sa");
	else if ((*stack_a)->content < (*stack_a)->next->content &&
		(*stack_a)->content > (*stack_a)->prev->content)
		choose_op(stack_a, stack_b, "rra");
	else if ((*stack_a)->next->content < (*stack_a)->content &&
		(*stack_a)->next->content > (*stack_a)->prev->content)
	{
		choose_op(stack_a, stack_b, "sa");
		choose_op(stack_a, stack_b, "rra");	
	}
	else
		choose_op(stack_a, stack_b, "ra");
}

int	find_min(t_stack **stack)
{
	int		min;
	t_stack	*temp;

	min = INT_MAX;
	temp = *stack;
	while ((*stack)->next)
	{
		if ((*stack)->content < min)
			min = (*stack)->content;
		(*stack) = (*stack)->next;
		if (temp == *stack)
			break ;
	}
	return (min);
}

void	sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(stack_a);
	if ((*stack_a)->prev->content == min)
		choose_op(stack_a, stack_b, "rra");
	else
		goto_val_a(stack_a, stack_b, min);
	choose_op(stack_a, stack_b, "pb");
	sort_3(stack_a, stack_b);
	choose_op(stack_a, stack_b, "pa");
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(stack_a);
	if ((*stack_a)->prev->content == min)
		choose_op(stack_a, stack_b, "rra");
	else
		goto_val_a(stack_a, stack_b, min);
	choose_op(stack_a, stack_b, "pb");
	sort_4(stack_a, stack_b);
	choose_op(stack_a, stack_b, "pa");
}