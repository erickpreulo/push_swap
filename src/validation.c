/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:02:39 by egomes            #+#    #+#             */
/*   Updated: 2021/08/30 18:42:46 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		isnbr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int		duplicate(t_ps *swap)
{
	int i;
	int j;

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

int		validation(t_ps *swap)
{
	swap->j = 0;
	swap->i = 1;
	while (swap->i < swap->ac)
	{
		if (isnbr(swap->av[swap->i]) || duplicate(swap))
			return (1);
		else if ((ft_atoi(swap->av[swap->i]) > INT16_MAX) 
			|| ft_strlen(swap->av[swap->i]) > 6)
			return (1);
		swap->i++;
	}
	return (0);
}
