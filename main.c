/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/26 14:24:49 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	//t_stack *stack_b;
	//size_t	size;
	
	if (ac == 1)
		return (1);
	//stack_b = NULL;
	stack_a = parser(av);
	//size = dblist_size(&stack_a);
	//bubble_sort(&stack_a, &stack_b);
	//choose_sort(&stack_a, &stack_b, size);
	//print_stack(stack_a);
	//printf("a = %i\n", stack_a->content);
	//printf("b = %i\n", stack_b->content);
	dblstdelete(stack_a);
	//dblstdelete(stack_b);
	return (0);
}
