/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/26 14:25:35 by lpittet          ###   ########.fr       */
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

void	goto_val_a(t_stack **stack_a, t_stack **stack_b, int goal)
{
	while ((*stack_a)->next)
	{
		if ((*stack_a)->content == goal
			|| ((*stack_a)->content < goal && (*stack_a)->prev->content > goal))
			break ;
		choose_op(stack_a, stack_b, "ra");
	}
}

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (stack->next)
	{
		printf("%i\t%u\n", stack->content, stack->index);
		stack = stack->next;
		if (stack == temp)
			break ;
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
	ft_printf("%s\n", op);
}