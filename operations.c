/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:06:49 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/19 14:29:36 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void swap(t_stack *stack)
{
	int	temp;
	
	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

t_stack *rotate(t_stack *stack)
{
	return (stack->next);
}

t_stack *rev_rotate(t_stack *stack)
{
	return (stack->prev);
}

void push(t_stack **stack_1, t_stack **stack_2)
{
	(*stack_1)->prev->next = (*stack_1)->next;
	(*stack_1)->next->prev = (*stack_1)->prev;
	(*stack_1)->prev = NULL;
	(*stack_1)->next = NULL;
	if (!(*stack_2))
		*stack_2 = *stack_1;
	else if (!(*stack_2)->next)
	{
		(*stack_2)->next = *stack_1;
		(*stack_2)->prev = *stack_1;
		(*stack_1)->next = *stack_2;
		(*stack_1)->prev = *stack_2;
		swap(*stack_2);
	}
	else
	{
		(*stack_1)->next = *stack_2;
		(*stack_2)->prev = (*stack_2)->prev;
		(*stack_2)->prev->next = *stack_1;
		(*stack_2)->prev = *stack_1;
		*stack_2 = rev_rotate(*stack_2);
	}

}
