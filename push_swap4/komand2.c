/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   komand2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:20:46 by truthe            #+#    #+#             */
/*   Updated: 2022/02/28 15:38:39 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **a, int flag)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*a) || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	tmp = *a;
	*a = (*a)->next;
	last->next = tmp;
	tmp->next = 0;
	if (flag)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **b, int flag)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*b) || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	tmp = *b;
	*b = (*b)->next;
	last->next = tmp;
	tmp->next = 0;
	if (flag)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_b, t_list **stack_a)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	write(1, "rr\n", 3);
}
