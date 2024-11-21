/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/21 08:29:09 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	//t_stack *stack_b;
	t_stack *temp;
	//t_stack *temp2;
	
	if (ac == 1)
		return (1);
	//stack_b = NULL;
	stack_a = parser(av);
	temp = stack_a;
	while (temp->next)
	{
		printf("input i = %d\n", temp->content);
		temp = temp->next;
		if (temp == stack_a)
			break ;
	}
	rev_rotate(&stack_a);
	printf("===REV. ROTATE DONE===\n");
	temp = stack_a;
	while (temp->next)
	{
		printf("stack a = %d\n", temp->content);
		temp = temp->next;
		if (temp == stack_a)
			break ;
	}
	printf("size = %lu", dblist_size(&stack_a));
	dblstdelete(stack_a);
	return (0);
}

//when parser complete just need to call it, remove if condition