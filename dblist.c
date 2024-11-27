/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dblist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 08:25:29 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/27 10:11:54 by lpittet          ###   ########.fr       */
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

t_stack	*dblstadd_back(t_stack *head, int content)
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

t_stack	*dblstadd_front(t_stack *head, int content)
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
	return (new);
}

void	dblstdelete(t_stack *head)
{
	t_stack	*temp;

	temp = head;
	if (head->prev)
		head->prev->next = NULL;
	while (temp->next)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
	free(head);
}

size_t	dblist_size(t_stack **stack)
{
	t_stack	*temp;
	size_t	i;

	temp = *stack;
	i = 0;
	if (!(temp))
		return (0);
	if (!(temp->next))
		return (1);
	while (temp->next)
	{
		temp = temp->next;
		i++;
		if (temp == *stack)
			break ;
	}
	return (i);
}
