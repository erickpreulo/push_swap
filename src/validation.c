/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:02:39 by egomes            #+#    #+#             */
/*   Updated: 2021/09/05 05:21:36 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isnbr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
		if ((str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	duplicate(t_ps *swap)
{
	int		i;
	int		j;

	i = 0;
	while (i < swap->ac - 1)
	{
		j = i + 1;
		while (j < swap->ac - 1)
		{
			if (swap->a[i] == swap->a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	validation(t_ps *swap)
{
	int	i;

	swap->j = 0;
	swap->i = 1;
	while (swap->i < swap->ac)
	{
		i = ft_atoi(swap->av[swap->i]);
		if (isnbr(swap->av[swap->i]) || duplicate(swap))
			return (1);
		if (i > 2147483647 || i < -2147483648)
			return (1);
		swap->i++;
	}
	return (0);
}
