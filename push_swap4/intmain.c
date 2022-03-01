/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:14:29 by truthe            #+#    #+#             */
/*   Updated: 2022/03/01 15:49:07 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	s;
	int			i;

	i = 1;
	if (argc <= 1)
		error();
	while (i < argc)
	{	
		ft_validation(argv[i]);
		i++;
	}
	s.stack_a = argv_add_to_list(argc, argv);
	if (sort_check(s.stack_a))
	{
		if (argc <= 6)
			ft_sort_five(&s);
		s.stack_b = 0;
		s.next = 0;
		if (argc > 6)
			sort_stack(&s);
	}
	list_delete(s.stack_a);
	return (0);
}
