/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_and_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:57:41 by truthe            #+#    #+#             */
/*   Updated: 2022/03/01 14:39:16 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_last_list(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_list	*ft_lstnew(int content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (0);
	list -> content = content;
	list -> flag = 0;
	list -> index = 0;
	list->next = NULL;
	return (list);
}

t_list	*make_index(t_list *lst, t_list *new)
{
	t_list	*p;

	p = lst;
	if (!lst)
		return (0);
	while (p->next != 0)
	{
		if (p->content == new->content)
			error();
		if (p->content > new->content)
			p->index++;
		else
			new->index++;
		p = p->next;
	}
	if (p->content == new->content)
		error();
	if (p->content > new->content)
			p->index++;
	else
		new->index++;
	return (p);
}

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*tmp;

	tmp = lst;
	count = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (*lst)
	{
		p = make_index(*lst, new);
		if (p == 0)
			return (0);
		p->next = new;
		new->next = NULL;
	}
	else
		*lst = new;
	return (1);
}
