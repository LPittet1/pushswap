/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:43:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 14:21:16 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	set_index(t_stack **stack, int min, unsigned int index)
{
	t_stack	*temp;

	temp = *stack;
	while ((*stack)->next)
	{
		if ((*stack)->content == min)
		{
			(*stack)->index = index;
			(*stack)->modulo = index % 10;
		}
		(*stack) = (*stack)->next;
		if (temp == *stack)
			break ;
	}
}

void	get_final_index(t_stack **stack, size_t size)
{
	size_t	i;
	int		min;

	i = 0;
	min = INT_MIN;
	while (i < size)
	{
		min = find_min(stack, min);
		set_index(stack, min, i);
		min += 1;
		i++;
	}
}

int	find_min(t_stack **stack, int last)
{
	int		min;
	t_stack	*temp;

	min = INT_MAX;
	temp = *stack;
	while ((*stack)->next)
	{
		if ((*stack)->content < min && (*stack)->content >= last)
			min = (*stack)->content;
		(*stack) = (*stack)->next;
		if (temp == *stack)
			break ;
	}
	return (min);
}

int	in_stack(t_stack **stack, int modulo)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	if (!(*stack) || !(*stack)->next)
		return (0);
	while (*stack)
	{
		if ((*stack)->modulo == modulo)
			i++;
		(*stack) = (*stack)->next;
		if (*stack == temp)
			break ;
	}
	return (i);
}

void	update_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (1)
	{
		(*stack)->index /= 10;
		(*stack)->modulo = (*stack)->index % 10;
		*stack = (*stack)->next;
		if (*stack == temp)
			break ;
	}
}
