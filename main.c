/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/19 08:34:20 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack *temp;
	
	if (ac == 1)
		return (1);
	stack_a = parser(av);
	temp = stack_a;
	while (temp->next)
	{
		printf("input i = %d\n", temp->content);
		temp = temp->next;
		if (temp == stack_a)
			break ;
	}
	dblstdelete(stack_a);
	return (0);
}

//when parser complete just need to call it, remove if condition