/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:06:49 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/21 09:05:13 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_stack **stack)
{
	int	temp;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	ft_printf("sa\n");
}

void	rotate(t_stack **stack)
{
	(*stack) = (*stack)->next;
	ft_printf("ra\n");
}

void	rev_rotate(t_stack **stack)
{
	(*stack) = (*stack)->prev;
	ft_printf("rra\n");
}

void	push(t_stack **stack_1, t_stack **stack_2)
{
	(*stack_2) = dblstadd_front((*stack_2), (*stack_1)->content);
	(*stack_1)->next->prev = (*stack_1)->prev;
	(*stack_1)->prev->next = (*stack_1)->next;
	free(*stack_1);
	(*stack_1) = (*stack_1)->next;
}
