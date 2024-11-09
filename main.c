/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/09 19:31:08 by lpittet          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pushswap.h"

int	main(int ac, char **av)
{
	int	*input;
	int	i;

	input = malloc(ac * (sizeof(int)));
	i = 1;
	if (ac < 1)
	{
		while (i < ac)
		{
			input[i] = ft_atoi(av[i]);
			i++;
		}
		input[i] == 0;
	}
	if (check_input)
		return (free(input), 1);
	return (0);

}
