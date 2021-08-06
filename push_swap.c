/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:08:45 by egomes            #+#    #+#             */
/*   Updated: 2021/08/06 22:06:37 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps *swap)
{
	if (swap->ac > 2)
		swap_sa(swap);
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
	while (swap->i < swap->ac)
	{
		swap->b[swap->i] = 0;
		swap->i++;
	}
}

void	print_array(t_ps *swap)
{
	swap->i = 0;
	while (swap->i < (swap->ac -1))
	{
		ft_putnbr(swap->a[swap->i]);
		ft_putchar(' ');
		if (swap->b[swap->i] != 0) 
			ft_putnbr(swap->b[swap->i]);
		ft_putchar('\n');
		swap->i++;
	}
	ft_putchar('a');
	ft_putstr(" b");
}

int		main(int ac, char **av)
{
	t_ps swap;
	int a[ac];
	int b[ac];

	swap.ac = ac;
	swap.a = a;
	swap.b = b;
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