/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:08:45 by egomes            #+#    #+#             */
/*   Updated: 2021/08/09 20:42:09 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(t_ps *swap)
{
	swap->i = 0;
	swap->j = 0;
	while (swap->i < (swap->ac - 1))
	{
		ft_putnbr(swap->a[swap->i]);
		ft_putchar(' ');
		if (swap->isb && swap->bsize >= (swap->ac - 2 - swap->i))
		{
			if (swap->j <= swap->bsize)
			{
				ft_putnbr(swap->b[swap->j]);
				swap->j++;
			}
		}
		ft_putchar('\n');
		swap->i++;
	}
	ft_putstr("_ _\n");
	ft_putstr("a b\n");
}

void	push_swap(t_ps *swap)
{
	if (swap->ac > 2)
	{
		swap_sa(swap);
		print_array(swap);
		ft_putchar('\n');
		swap_pb(swap);
		print_array(swap);
		ft_putchar('\n');
		swap_pb(swap);
		print_array(swap);
		ft_putchar('\n');
		swap_pb(swap);
		print_array(swap);
		ft_putchar('\n');
		swap_ra(swap);
		print_array(swap);
		ft_putchar('\n');
		swap_rb(swap);
		print_array(swap);
		ft_putchar('\n');
		swap_rra(swap);
		print_array(swap);
		ft_putchar('\n');
		swap_sa(swap);
	}
}

void	take_array(t_ps *swap)
{
	swap->j = 0;
	swap->i = 1;
	swap->isb = 0;
	while (swap->av[swap->i] != 0)
	{
		swap->a[swap->j++] = ft_atoi(swap->av[swap->i++]);
	}
	swap->a[swap->j] = 0;
	swap->i = 0;
}

int		main(int ac, char **av)
{
	t_ps swap;
	int a[ac];

	swap.count = 0;
	swap.countb = 0;
	swap.size = 0;
	swap.bsize = 0;
	swap.ac = ac;
	swap.a = a;
	swap.av = av;
	if (ac < 2)
		ft_putstr("Error");
	else
	{
		take_array(&swap);
		if (validation(&swap))
		{
			ft_putstr("Error\n");
			return (0);
		}
		push_swap(&swap);
		print_array(&swap);
	}
	ft_putchar('\n');
	return (0);
}
