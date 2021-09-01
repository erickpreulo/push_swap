/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 04:10:53 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 04:13:36 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_a_and_b(t_ps *swap)
{
	int	i;

	i = 0;
	while ((swap->i <= (swap->ac - 2))
		|| ((swap->isb) && swap->j <= swap->bsize))
	{
		if (swap->bsize >= (swap->ac - 1) && i <= swap->bsize - (swap->ac - 1))
			i++;
		else
		{
			ft_putnbr(swap->a[swap->i]);
			swap->i++;
		}
		ft_putchar('	');
		if (swap->isb && swap->bsize >= (swap->ac - 1 - swap->i))
		{
			if (swap->j <= swap->bsize)
			{
				ft_putnbr(swap->b[swap->j]);
				swap->j++;
			}
		}
		ft_putchar('\n');
	}
}

void	print_array(t_ps *swap)
{
	swap->i = 0;
	swap->j = 0;
	ft_putstr("stacks\n");
	print_a_and_b(swap);
	swap->ss = 0;
	swap->rr = 0;
	swap->rrr = 0;
	ft_putstr("_	_\n");
	ft_putstr("a	b\n");
}

void	save_commands(t_ps *swap, char *str)
{
	swap->commands[swap->countcomm] = str;
	swap->countcomm++;
}

void	print_commands(t_ps *swap)
{
	int	i;

	i = 0;
	while (i < swap->countcomm)
	{
		ft_putstr(swap->commands[i]);
		i++;
	}
}

void	print(int *nbr)
{
	int	i;

	i = 0;
	while (i <= 8)
	{
		ft_putnbr(nbr[i]);
		i++;
	}
}
