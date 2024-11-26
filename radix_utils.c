/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:43:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/26 10:13:30 by lpittet          ###   ########.fr       */
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
	int 	min;

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

void	go_to_val_b(t_stack **stack_a, t_stack **stack_b, int modulo)
{
	if ((*stack_b)->modulo - modulo > 5
		|| (*stack_b)->modulo - modulo < -5)
	{
		while (*stack_b)
		{
			choose_op(stack_a, stack_b, "rrb");
			if (((*stack_b)->prev->modulo > modulo + 1
				&& (*stack_b)->modulo <= modulo))
				break ;
		}
	}
	else
	{
		while (*stack_b)
		{
			choose_op(stack_a, stack_b, "rb");
			if (((*stack_b)->prev->modulo > modulo + 1
				&& (*stack_b)->modulo <= modulo))
				break ;
		}
	}
}

int	in_stack(t_stack **stack, int modulo)
{
	int	i;
	t_stack *temp;

	i = 0;
	temp = *stack;
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
// TODO changer les conditions des boucles while pour s'assurer que ca marche quand les valeurs ne sont pas exactes