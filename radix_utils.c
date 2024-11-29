/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:43:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/29 13:36:11 by lpittet          ###   ########.fr       */
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
