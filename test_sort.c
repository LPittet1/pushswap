/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:30:51 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/25 09:42:16 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	choose_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	if (!is_sorted(stack_a))
		return ;
	if (size == 2)
		choose_op(stack_a, stack_b, "sa");
	else if (size == 3)
		sort_3(stack_a, stack_b);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
	{
		get_final_index(stack_a, size);
	}
}