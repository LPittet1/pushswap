/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:43:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/21 09:16:47 by lpittet          ###   ########.fr       */
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