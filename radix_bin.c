/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:40:47 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/29 13:32:35 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void	radix_bin_a(t_stack **a, t_stack **b, int mask, size_t len)
{
	while (len)
	{
		if ((*a)->index & mask)
			choose_op(a, b, "ra");
		else
			choose_op(a, b, "pb");
		len--;
	}
}

static	void	radix_bin_b(t_stack **a, t_stack **b, int mask, size_t len)
{
	size_t	new_len;

	new_len = dblist_size(b);
	if (len)
	{
		while (new_len)
		{
			if ((*b)->index & mask)
				choose_op(a, b, "pa");
			else
				choose_op(a, b, "rb");
			new_len--;
		}
	}
}

void	radix_bin(t_stack **a, t_stack **b, size_t msb)
{
	size_t	lena;
	size_t	lenb;
	int		mask;

	mask = 1;
	while (msb)
	{
		lena = dblist_size(a);
		lenb = dblist_size(b);
		radix_bin_a(a, b, mask, lena);
		radix_bin_b(a, b, mask, lenb);
		mask <<= 1;
		msb--;
	}
	while (*b)
		choose_op(a, b, "pa");
}
