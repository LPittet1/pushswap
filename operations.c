/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:06:49 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/20 16:41:31 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack *stack)
{
	int	temp;

	temp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = temp;
}

void	rotate(t_stack **stack)
{
	(*stack) = (*stack)->next;
}

void	rev_rotate(t_stack **stack)
{
	(*stack) = (*stack)->prev;
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	(*stack_2) = dblstadd_front((*stack_2), (*stack_1)->content);
	(*stack_1)->next->prev = (*stack_1)->prev;
	(*stack_1)->prev->next = (*stack_1)->next;
	free(*stack_1);
	(*stack_1) = (*stack_1)->next;
}
