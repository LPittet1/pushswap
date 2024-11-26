/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:06:49 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/25 14:56:28 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack **stack)
{
	int	temp;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
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
	t_stack *temp;
	
	(*stack_2) = dblstadd_front((*stack_2), (*stack_1)->content);
	(*stack_2)->index = (*stack_1)->index;
	(*stack_2)->modulo = (*stack_1)->modulo;
	temp = *stack_1;
	if (dblist_size(stack_1) > 2)
	{
		(*stack_1)->next->prev = (*stack_1)->prev;
		(*stack_1)->prev->next = (*stack_1)->next;
		(*stack_1) = (*stack_1)->next;
	}
	else if (dblist_size(stack_1) == 2)
	{
		(*stack_1)->next->prev = NULL;
		(*stack_1)->prev->next = NULL;
		(*stack_1) = (*stack_1)->next;
	}
	else
		(*stack_1) = NULL;
	free(temp);
}
