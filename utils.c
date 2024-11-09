/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:13:14 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/09 19:26:05 by lpittet          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pushswap.h"

int	check_input(int *input)
{
	int	i;
	int j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (j < i)
		{
			if (input[i] == input[j])
				write(1, "wrong input", 11);
				//return (1);
			j++;
		}
		i++;
	}
	return (0);
}