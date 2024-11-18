/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/18 14:30:21 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *temp;
	
	if (ac == 1)
		return (1);
	printf("%s\n", av[0]);
	stack_a = parser(av);
	temp = stack_a;
	while (stack_a->next != temp)
	{
		printf("input i = %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	dblstdelete(stack_a);
	return (0);
}

//when parser complete just need to call it, remove if condition