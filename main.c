/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/19 14:41:20 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack *temp;
	t_stack *temp2;
	
	if (ac == 1)
		return (1);
	stack_b = NULL;
	stack_a = parser(av);
	temp = stack_a;
	while (temp->next)
	{
		printf("input i = %d\n", temp->content);
		temp = temp->next;
		if (temp == stack_a)
			break ;
	}
	push(&stack_a, &stack_b);
	printf("===PUSH DONE===\n");
	temp = stack_a;
	printf("stack a = %d\n", temp->content);
	while (temp->next)
	{
		printf("stack a = %d\n", temp->content);
		temp = temp->next;
		if (temp == stack_a)
			break ;
	}
	temp2 = stack_b;
	printf("stack b = %d\n", temp2->content);
	while (temp2->next)
	{
		printf("stack b = %d\n", temp2->content);
		temp2 = temp->next;
		if (temp2 == stack_b)
			break ;
	}
	dblstdelete(stack_a);
	return (0);
}

//when parser complete just need to call it, remove if condition