/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:08:45 by egomes            #+#    #+#             */
/*   Updated: 2021/09/05 05:19:16 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps *swap)
{
	if (swap->ac > 2)
	{
		if (order_verify(swap))
		{
			if (swap->find_v)
			{
				save_commands(swap, "\n");
				print_array(swap);
			}
			order_form(swap);
		}
		else if (swap->find_v)
			print_array(swap);
	}
}

void	take_array(t_ps *swap)
{
	swap->j = 0;
	swap->i = 1;
	while (swap->av[swap->i] != 0)
	{
		swap->a[swap->j++] = ft_atoi(swap->av[swap->i++]);
	}
	swap->a[swap->j] = 0;
	swap->i = 0;
}

void	init_struct(t_ps *swap)
{
	swap->ss = 0;
	swap->rr = 0;
	swap->rrr = 0;
	swap->isa = 0;
	swap->isb = 0;
	swap->changea = 0;
	swap->changeb = 0;
	swap->countb = 0;
	swap->bsize = 0;
	swap->find_v = 0;
	swap->countcomm = 0;
	swap->sortlow = 0;
	swap->sortbhigh = 0;
	swap->sortlaststack = 0;
	swap->countstack = 0;
}

int	main(int ac, char **av)
{
	t_ps	swap;

	if (ac < 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	init_struct(&swap);
	swap.ac = ac;
	swap.cpyac = ac;
	swap.av = av;
	find_v(av[1], &swap);
	if (swap.find_v)
		change_av(&swap);
	take_array(&swap);
	if (validation(&swap))
	{
		ft_putstr("Error\n");
		return (0);
	}
	push_swap(&swap);
	print_commands(&swap);
	return (0);
}
