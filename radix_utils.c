/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:43:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/29 10:35:36 by lpittet          ###   ########.fr       */
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

	i = 1;
	min = INT_MIN;
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

int	get_msb(size_t size)
{
	int	i;

	i = 0;
	while (size)
	{
		size /= 2;
		i++;
	}
	return (i);
}

void	choose_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	int	msb;

	if (!is_sorted(stack_a))
		return ;
	if (size == 2)
		choose_op(stack_a, stack_b, "sa");
	else if (size == 3)
		sort_3(stack_a, stack_b);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
	{
		get_final_index(stack_a, size);
		msb = get_msb(size);
		radix_bin(stack_a, stack_b, msb);
	}
}
