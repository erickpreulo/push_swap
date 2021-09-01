/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_magic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 00:19:54 by egomes            #+#    #+#             */
/*   Updated: 2021/08/30 18:02:22 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_b_high(t_ps *swap)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	if (swap->bsize == 0)
		return (swap->b[0]);
	while (i <= swap->bsize)
	{
		j = 0;
		size = 0;
		while (j <= swap->bsize)
		{
			if (swap->b[i] > swap->b[j])
				size++;
			if (size == swap->bsize)
			{
				swap->sortbhigh = swap->b[i];
				return (swap->sortbhigh);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	less_stack_position_ra(t_ps *swap)
{
	int		i;

	i = 0;
	while (i <= swap->ac - 2)
	{
		if (swap->a[i] < swap->sortlaststack && i <= (swap->ac - 2) / 2)
			return (1);
		i++;
	}
	return (0);
}

int	less_stack_position_rb(t_ps *swap)
{
	int		i;

	i = 0;
	while (i <= swap->bsize / 2)
	{
		if (swap->b[i] == swap->sortbhigh)
			return (1);
		i++;
	}
	return (0);
}

int	sort_a_last_stack_100(t_ps *swap)
{
	swap->i = 0;
	while (swap->i <= swap->ac - 2)
	{
		swap->j = 0;
		swap->size_stack = 0;
		swap->less_size_stack = 0;
		while (swap->j <= swap->ac - 1)
		{
			if (swap->a[swap->i] >= swap->a[swap->j])
				swap->size_stack++;
			if (swap->a[swap->i] < swap->a[swap->j])
				swap->less_size_stack++;
			if (swap->size_stack == 10
				&& swap->less_size_stack == swap->ac - 12)
			{
				swap->sortlaststack = swap->a[swap->i];
				return (swap->sortlaststack);
			}
			swap->j++;
		}
		swap->i++;
	}
	return (0);
}

int	sort_a_last_stack_500(t_ps *swap)
{
	swap->i = 0;
	while (swap->i <= swap->ac - 2)
	{
		swap->j = 0;
		swap->size_stack = 0;
		swap->less_size_stack = 0;
		while (swap->j <= swap->ac - 1)
		{
			if (swap->a[swap->i] >= swap->a[swap->j])
				swap->size_stack++;
			if (swap->a[swap->i] < swap->a[swap->j])
				swap->less_size_stack++;
			if (swap->size_stack == 50
				&& swap->less_size_stack == swap->ac - 52)
			{
				swap->sortlaststack = swap->a[swap->i];
				return (swap->sortlaststack);
			}
			swap->j++;
		}
		swap->i++;
	}
	return (0);
}
