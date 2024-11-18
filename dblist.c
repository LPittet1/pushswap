/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:25:29 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/18 14:18:04 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*dblstnew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->content = content;
	new->next = NULL;
	return (new);
}

t_stack	*dblstadd(t_stack *head, int content)
{
	t_stack	*new;

	new = dblstnew(content);
	if (!head)
		head = new;
	else if (!head->next)
	{
		head->next = new;
		head->prev = new;
		new->prev = head;
		new->next = head;
	}
	else
	{
		head->prev->next = new;
		new->prev = head->prev;
		new->next = head;
		head->prev = new;
	}
	return (head);
}

void	dblstdelete(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	head->prev->next = NULL;
	while (temp->next)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	free(head);
}

// int	main()
// {
// 	t_stack *test = NULL;
// 	t_stack *temp;
// 	int i =  0;
// 	while (i < 5)
// 	{
// 		test = dblstadd(test, i);
// 		i++;
// 	}
// 	temp = test;
// 	while (test->next != temp)
// 	{
// 		printf("test = %i\n", test->content);
// 		test = test->next;
// 	}
// 	printf("test = %i\n", test->content);
// 	dblstdelete(test);
// }