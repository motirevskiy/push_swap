/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   komand3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:39:20 by truthe            #+#    #+#             */
/*   Updated: 2022/02/28 15:43:09 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **stack_a, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_a);
	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack_a;
	*stack_a = tmp2;
	if (flag)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b, int flag)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*stack_b);
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack_b;
	*stack_b = tmp2;
	if (flag)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
