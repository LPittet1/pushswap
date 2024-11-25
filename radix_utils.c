/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:43:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/25 10:17:30 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	set_index(t_stack **stack, int min, unsigned int index)
{
	t_stack *temp;

	temp = *stack;
	while ((*stack)->next)
	{
		if ((*stack)->content == min)
			(*stack)->index = index;
		(*stack) = (*stack)->next;
		if (temp == *stack)
			break ;
	}
}

void	get_final_index(t_stack **stack, size_t size)
{
	size_t	i;
	int 	min;

	i = 1;
	min = INT_MIN;
	ft_printf("size = %i\n", size);
	while (i <= size)
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