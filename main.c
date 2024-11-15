/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/15 14:32:49 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	stack_a;
	int		i;

	i  = 0;
	if (ac == 1)
		return (1);
	stack_a = parser(av);
	while (i < stack_a.size)
	{
		printf("input i = %d\n", stack_a.content[i]);
		i++;
	}
	free(stack_a.content);
	return (0);
}

//when parser complete just need to call it, remove if condition