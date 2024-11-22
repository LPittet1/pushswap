/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 10:51:02 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/22 14:36:16 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_stack **stack)
{
	if ((*stack)->prev->content > (*stack)->content &&
		(*stack)->prev->content < (*stack)->next->content)
	{
		swap(stack);
		rotate(stack);
	}
	else if ((*stack)->content > (*stack)->next->content &&
		(*stack)->content < (*stack)->prev->content)
		swap(stack);
	else if ((*stack)->content < (*stack)->next->content &&
		(*stack)->content > (*stack)->prev->content)
		rev_rotate(stack);
	else if ((*stack)->next->content < (*stack)->content &&
		(*stack)->next->content > (*stack)->prev->content)
	{
		swap(stack);
		rev_rotate(stack);	
	}
	else
		rotate(stack);
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
		rev_rotate(stack_a);
	else
		goto_val(stack_a, min);
	push(stack_a, stack_b);
	ft_printf("pb\n");
	sort_3(stack_a);
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(stack_a);
	if ((*stack_a)->prev->content == min)
		rev_rotate(stack_a);
	else
		goto_val(stack_a, min);
	push(stack_a, stack_b);
	ft_printf("pb\n");
	sort_4(stack_a, stack_b);
	push(stack_b, stack_a);
	ft_printf("pa\n");
}