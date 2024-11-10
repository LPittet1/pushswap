/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:06:21 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/09 22:11:21 by lpittet          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "pushswap.h"

int	main(int ac, char **av)
{
	int		*input;
	int		i;

	input = malloc(ac * (sizeof(int)));
	i = 0;
	if (parser(av))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	while (i < ac - 1)
	{
		input[i] = ft_atoi(av[i + 1]);
		i++;
	}
	input[i] == 0;
	check_repeat(input);
	free(input);
	return (0);
}

//when parser complete just need to call it, remove if condition