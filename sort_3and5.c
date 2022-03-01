/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3and5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:00:41 by truthe            #+#    #+#             */
/*   Updated: 2022/02/28 21:16:35 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_stacks *s)
{
	int	a;
	int	b;
	int	c;

	a = s->stack_a->content;
	b = s->stack_a->next->content;
	c = s->stack_a->next->next->content;
	if (a > c && b > c && b < a)
	{
		ft_ra(&s->stack_a, 1);
		ft_sa(&s->stack_a, 1);
	}
	else if (a > b && c > b && a > c)
		ft_ra(&s->stack_a, 1);
	else if (c > a && a > b && c > b)
		ft_sa(&s->stack_a, 1);
	else if (b > a && a > c && c < b)
		ft_rra(&s->stack_a, 1);
	else if (b > a && c > a && c < b)
	{
		ft_sa(&s->stack_a, 1);
		ft_ra(&s->stack_a, 1);
	}
}

void	small_sort(t_stacks *s)
{
	int	first;
	int	last;

	first = s->stack_a->content;
	last = s->stack_a->next->content;
	if (ft_lstsize(s->stack_a) == 2 && first > last)
		ft_ra(&s->stack_a, 1);
	else if (ft_lstsize(s->stack_a) == 3)
		ft_sort_three(s);
}

int	min_index(t_list *list)
{
	t_list	*tmp;
	int		min;

	tmp = list;
	min = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

int	index_in_stack(t_list *list, int num)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = 0;
	while (tmp->index != num && tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_sort_five(t_stacks *s)
{
	int	i;

	i = 0;
	while (ft_lstsize(s->stack_a) > 3)
	{
		if (index_in_stack(s->stack_a, min_index(s->stack_a)) == 0)
			ft_pb(&s->stack_a, &s->stack_b);
		else if (index_in_stack(s->stack_a, min_index(s->stack_a))
			>= (ft_lstsize(s->stack_a) / 2 + 1))
			ft_rra(&s->stack_a, 1);
		else if (index_in_stack(s->stack_a, min_index(s->stack_a))
			< (ft_lstsize(s->stack_a) / 2 + 1))
			ft_ra(&s->stack_a, 1);
	}
	small_sort(s);
	while (s->stack_b != NULL)
		ft_pa(&s->stack_a, &s->stack_b);
}
