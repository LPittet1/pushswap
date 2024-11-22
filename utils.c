/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/22 14:19:43 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack **stack)
{
	int i;
	t_stack *temp;
	
	i = 0;
	temp = *stack;
	if (dblist_size(stack) <= 1)
		return (0);
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			i++;
		temp = temp->next;
		if (temp->next == *stack)
			break ;
	}
	return (i);
}

int is_sorted_reverse(t_stack **stack)
{
	int i;
	t_stack *temp;
	
	i = 0;
	temp = *stack;
	if (dblist_size(stack) <= 1)
		return (0);
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			i++;
		temp = temp->next;
		if (temp->next == *stack)
			break ;
	}
	return (i);
}

void	goto_val(t_stack **stack, int goal)
{
	while ((*stack)->next)
	{
		if ((*stack)->content == goal
			|| ((*stack)->content < goal && (*stack)->prev->content > goal))
			break ;
		rotate(stack);
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack->next)
	{
		printf("%i\n", stack->content);
		stack = stack->next;
		if (stack == temp)
			break ;
	}
}
