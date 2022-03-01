/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:36:10 by truthe            #+#    #+#             */
/*   Updated: 2022/03/01 14:36:13 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_sort(t_stacks *s, int flag)
{
	if (flag)
		ft_pa (&s->stack_a, &s->stack_b);
	s->stack_a->flag = -1;
	ft_ra(&s->stack_a, 1);
	s->next++;
	check_next(s);
	return (1);
}

int	check_next(t_stacks *s)
{
	if (s->stack_a->index == s->next)
		return (push_to_sort(s, 0));
	if (ft_lstsize(s->stack_b) > 0 && s->stack_b->index == s->next)
		return (push_to_sort(s, 1));
	if (ft_lstsize(s->stack_b) >= 3
		&& ft_last_list(s->stack_b)->index == s->next)
	{
		ft_rrb(&s->stack_b, 1);
		return (push_to_sort(s, 1));
	}
	if (ft_lstsize(s->stack_b) > 1 && s->stack_b->next->index == s->next + 1
		&& s->stack_a->next->index == s->next)
	{
		ft_ss(&s->stack_a, &s->stack_b);
		s->stack_a->flag = -1;
		ft_ra(&s->stack_a, 1);
		s->next++;
		return (push_to_sort(s, 1));
	}
	return (0);
}

void	empty_stack_b(t_stacks *s, int flag)
{
	int	i;
	int	mid;
	int	k;

	while (s->stack_b)
	{
		i = 0;
		flag++;
		k = ft_lstsize(s->stack_b);
		mid = k / 2 + s->next + 2;
		while (s->stack_b && i++ < k)
		{
			s->stack_b->flag = flag;
			if (s->stack_b->index >= mid || s->stack_b->index == s->next)
			{
				ft_pa(&s->stack_a, &s->stack_b);
				check_next(s);
			}
			else if (s->stack_b)
				ft_rb(&s->stack_b, 1);
		}
	}
}

void	sort_stack(t_stacks *s)
{
	int	i;
	int	flag;
	int	k;

	k = ft_lstsize(s->stack_a);
	i = 0;
	while (i++ < k)
	{
		if (s->stack_a->index <= k / 2)
			ft_pb(&s->stack_a, &s->stack_b);
		else
			ft_ra(&s->stack_a, 1);
	}
	while (s->next < k)
	{
		flag = s->stack_a->flag;
		while (s->stack_a && s->stack_a->flag == flag && s->next > 0)
		{
			if (!check_next(s))
				ft_pb(&s->stack_a, &s->stack_b);
		}
		empty_stack_b(s, flag);
	}
}
