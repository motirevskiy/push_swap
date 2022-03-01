/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:34:14 by truthe            #+#    #+#             */
/*   Updated: 2022/03/01 15:39:58 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*argv_add_to_list(int argc, char **argv)
{
	char	**str;
	t_list	*tmp2;
	t_list	*a;
	int		j;
	int		i;

	a = NULL;
	i = 1;
	while (--argc)
	{
		j = 0;
		str = ft_split(argv[i], ' ');
		while (str[j])
		{
			tmp2 = ft_lstnew(ft_atoi(str[j]));
			if (!tmp2 || !ft_lstadd_back(&a, tmp2))
				exit(1);
			free(str[j]);
			j++;
		}
		free(str);
		i++;
	}	
	return (a);
}
