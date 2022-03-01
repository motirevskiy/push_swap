/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   komand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgretche <cgretche@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:17:30 by truthe            #+#    #+#             */
/*   Updated: 2022/03/01 20:50:53 by cgretche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa(t_list **stack_a, int flag) // поменять местами первые 2 элемента на вершине стека a
{
	t_list	*tmp;

	if (!stack_a)
		return ;
	tmp = (*stack_a)->next;       //указатель на второй элемент
	(*stack_a)->next = (*stack_a)->next->next;     //указатель на 2 стал ук. на 3
	tmp->next = (*stack_a);       //ук. на 2 стал ук. на 1
	*stack_a = tmp;       //ук. на 1 стал ук. на 2
	if (flag)
		write(1, "sa\n", 3);
}

void    ft_sb(t_list **stack_b, int flag) // поменять местами первые 2 элемента на вершине стека b
{
	t_list	*tmp;

	if (!stack_b)
		return ;
	tmp = (*stack_b)->next;       //указатель на второй элемент
	(*stack_b)->next = (*stack_b)->next->next;     //указатель на 2 стал ук. на 3
	tmp->next = (*stack_b);       //ук. на 2 стал ук. на 1
	*stack_b = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **a, t_list	**b)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = (*a)->next->next;
	tmp->next = (*a);
	*a = tmp;
	tmp = (*b)->next;
	(*b)->next = (*b)->next->next;
	tmp->next = (*b);
	*b = tmp;
	write(1, "ss\n", 3);
}

void	ft_pa(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*b == 0)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **a, t_list **b)
{
	t_list	*tmp;

	if (*a == 0)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
}
