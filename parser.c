/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:27:27 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/15 14:11:18 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_repeat(int *input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (j < i)
		{
			if (input[i] == input[j])
				exit (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_int(char *s)
{
	size_t	len;

	len = 0;
	if (s[0] == '-')
		len++;
	while (ft_isdigit(s[len]))
		len++;
	if (len != ft_strlen(s))
		return (1);
	if (s[0] == '-')
	{
		if (len > 11)
			return (1);
		else if (len == 11)
			return (ft_strncmp(s, "-2147483648", 11));
	}
	else
	{
		if (len > 10)
			return (1);
		else if (len == 10)
			return (ft_strncmp(s, "2147483647", 11));
	}
	return (0);
}

static t_stack	*fill_init(char *s, t_stack *stack)
{
	int		i;
	int		j;
	char	**table;

	i = 0;
	j = 0;
	table = ft_split(s, ' ');
	while (table[i])
	{
		if (check_int(table[i]) > 0)
			exit(1);
		stack->content = ft_realloc(stack->content, 1);
		stack->content[j] = ft_atoi(table[i]);
		i++;
		j++;
		stack->size++;
	}
	free(table);
	return (stack);
}

t_stack	parser(char **av)
{
	t_stack	stack_a;
	int		i;
	
	i = 1;
	stack_a.content = ft_calloc(1, sizeof(int));
	stack_a.size = 0;
	stack_a.name = 'a';
	while (av[i])
	{
		fill_init(av[i], &stack_a);	
		i++;
	}
	check_repeat(stack_a.content);
	return (stack_a);
}

// need to create a function that exit if error input replace all return (1) with it
// then transform to void func, no need to return anything exit or ok
// same for check repeat
// line 49 need to create atol or find something similar