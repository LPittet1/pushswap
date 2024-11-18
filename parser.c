/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:27:27 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/18 14:34:30 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static t_stack	*fill_init(char **av, t_stack *stack)
{
	int		i;

	i = 1;
	if (check_int(av) > 0)
		exit(1);
	stack = dblstadd(stack, ft_atoi(av[i]));
		i++;
	return (stack);
}

t_stack	*parser(char **av)
{
	t_stack	*stack_a;
	int		i;
	
	i = 1;
	stack_a = NULL;
	fill_init(av, stack_a);	
	return (stack_a);
}

// need to create a function that exit if error input replace all return (1) with it and free stack
// same for check repeat
