/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:54:39 by truthe            #+#    #+#             */
/*   Updated: 2022/03/01 20:52:11 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c == '-' || c == '+')
		return (1);
	else
		error();
	return (0);
}

t_list	*sort_check(t_list *lst)
{
	t_list	*p;

	p = lst;
	while (p->next != NULL)
	{
		if (p->content < p->next->content)
			p = p->next;
		else
			break ;
	}
	if (p->next == NULL)
		return (0);
	return (p);
}

int	ft_validation(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]))
		i++;
	}
	return (0);
}

void	list_delete(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp)
			free(tmp);
	}
}
