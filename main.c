/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/29 13:56:38 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	size_t	size;

	if (ac == 1)
		return (1);
	stack_b = NULL;
	stack_a = parser(av);
	if (!stack_a)
		return (1);
	size = dblist_size(&stack_a);
	choose_sort(&stack_a, &stack_b, size);
	dblstdelete(stack_a);
	return (0);
}
