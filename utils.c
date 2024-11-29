/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/29 13:36:20 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack **stack)
{
	int		i;
	t_stack	*temp;

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

void	goto_val_a(t_stack **stack_a, t_stack **stack_b, int goal)
{
	size_t	i;
	t_stack	*temp;

	i = 0;
	temp = *stack_a;
	if ((*stack_a)->content == goal)
		return ;
	while ((*stack_a)->content != goal)
	{
		(*stack_a) = (*stack_a)->next;
		i++;
	}
	while ((*stack_a) != temp)
		(*stack_a) = (*stack_a)->next;
	if (i <= dblist_size(stack_a) / 2)
	{
		while ((*stack_a)->content != goal)
			choose_op(stack_a, stack_b, "ra");
	}
	else
	{
		while ((*stack_a)->content != goal)
			choose_op(stack_a, stack_b, "rra");
	}
}

void	choose_op(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (!ft_strncmp(op, "sa", 3))
		swap(stack_a);
	else if (!ft_strncmp(op, "sb", 3))
		swap(stack_b);
	else if (!ft_strncmp(op, "ra", 3))
		rotate(stack_a);
	else if (!ft_strncmp(op, "rb", 3))
		rotate(stack_b);
	else if (!ft_strncmp(op, "rra", 4))
		rev_rotate(stack_a);
	else if (!ft_strncmp(op, "rrb", 4))
		rev_rotate(stack_b);
	else if (!ft_strncmp(op, "pa", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(op, "pb", 3))
		push(stack_a, stack_b);
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
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

void	choose_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	int	msb;

	if (!is_sorted(stack_a))
		return ;
	if (size == 2)
		choose_op(stack_a, stack_b, "sa");
	else if (size == 3)
		sort_3(stack_a, stack_b);
	else if (size <= 45)
		insert_sort(stack_a, stack_b);
	else
	{
		get_final_index(stack_a, size);
		msb = get_msb(size);
		radix_bin(stack_a, stack_b, msb);
	}
}
