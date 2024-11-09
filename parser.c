/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:27:27 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/09 22:05:20 by lpittet          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pushswap.h"
int	check_repeat(int *input)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parser(char **input)
{
	int i;
	int	j;
	
	i = 1;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (!ft_isdigit(input[i][j]))
				return (1);
			j++;
		}
		if (INT_MIN > atol(input[i]) || atol(input[i]) > INT_MAX)
			return (1);
		i++;
	}
	if (i == 1)
		return (1);
	return(0);
}

// need to create a function that exit if error input replace all return (1) with it
// then transform to void func, no need to return anything exit or ok
// same for check repeat
// line 49 need to create atol or find something similar