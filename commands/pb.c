/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 03:46:11 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 03:47:00 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	changeorder_b(t_ps *swap)
{
	int		buf[3000];
	int		i;

	i = 0;
	while (i < swap->countb)
	{
		buf[i] = swap->b[i];
		i++;
	}
	buf[i] = 0;
	if (swap->countb == 0)
		swap->b[swap->countb] = swap->a[0];
	else
	{
		swap->i = 1;
		while (swap->i <= swap->changeb)
		{
			swap->b[swap->i] = buf[swap->i - 1];
			swap->i++;
		}
		swap->b[0] = swap->a[0];
	}
	swap->changeb++;
}

void	less_a(t_ps *swap)
{
	int		i;

	i = 0;
	while (i <= swap->ac - 3)
	{
		swap->a[i] = swap->a[i + 1];
		i++;
	}
	swap->ac--;
}

void	swap_pb(t_ps *swap)
{
	if (swap->find_v)
		ft_putstr("\npb\n");
	changeorder_b(swap);
	swap->isb = 1;
	swap->bsize = swap->countb;
	swap->countb++;
	less_a(swap);
	if (swap->find_v)
		print_array(swap);
	save_commands(swap, "pb\n");
}
