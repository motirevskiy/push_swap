/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truthe <truthe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:42:32 by truthe            #+#    #+#             */
/*   Updated: 2022/03/01 15:06:02 by truthe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int			i;
	long int	res;
	int			flag;

	i = 0;
	res = 0;
	flag = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || \
	str[i] == '\f' || str[i] == '\n' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * flag));
}

int	ft_strncmp(const char *string1, const char *string2, size_t num )
{
	size_t	i;

	i = 0;
	while (i < num && (string1[i] || string2[i]))
	{
		if (string1[i] != string2[i])
			return ((unsigned char)string1[i] - (unsigned char)string2[i]);
		i++;
	}
	return (0);
}
