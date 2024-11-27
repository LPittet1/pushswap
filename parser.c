/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:27:27 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 12:48:29 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	void	parsing_error(t_stack *stack, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	ft_free_tab(tab, i);
	if (stack)
		dblstdelete(stack);
	ft_putendl_fd("Error", 2);
	exit (1);
}

static	int	check_int(char *num)
{
	size_t	i;

	i = 0;
	while ((i == 0 && num[i] == '-') || (num[i] && ft_isdigit(num[i])))
		i++;
	if (i != ft_strlen(num))
		return (1);
	if (num[0] == '-')
	{
		if (i < 11)
			return (0);
		else if (i > 11)
			return (1);
		else
			return (ft_strncmp(num, "-2147483648", 11));
	}
	else
	{
		if (i < 10)
			return (0);
		else if (i > 10)
			return (1);
		else
			return (ft_strncmp(num, "2147483647", 10));
	}
}

static	int	check_all(char *num, t_stack *stack)
{
	t_stack	*temp;
	int		n;

	temp = stack;
	if (check_int(num) > 0)
		return (1);
	if (!temp)
		return (0);
	n = ft_atoi(num);
	if (!temp->next)
		return (n == temp->content);
	while (temp->next)
	{
		if (n == temp->content)
			return (1);
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (0);
}

t_stack	*parser(char **av)
{
	t_stack	*stack_a;
	char	**tab;
	int		i;
	int		j;

	i = 1;
	stack_a = NULL;
	while (av[i])
	{
		tab = ft_split(av[i], ' ');
		j = 0;
		while (tab[j])
		{
			if (check_all(tab[j], stack_a) == 0)
				stack_a = dblstadd_back(stack_a, ft_atoi(tab[j]));
			else
				parsing_error(stack_a, tab);
			j++;
		}
		ft_free_tab(tab, j);
		i++;
	}
	return (stack_a);
}