/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:08:45 by egomes            #+#    #+#             */
/*   Updated: 2021/08/05 13:32:41 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	takearray(t_ps *swap)
{
	int i;
	int j;

	j = 0;
	i = 1;
	while (swap->av[i] != 0)
		swap->a[j++] = ft_atoi(swap->av[i++]);
}

void	printarray(t_ps *swap)
{
	int i;

	i = 0;
	while (i < (swap->ac -1))
	{
		ft_putnbr(swap->a[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('a');
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
		ft_putstr("ERROR");
	else
	{
		takearray(&swap);
		printarray(&swap);
	}
	ft_putchar('\n');
	return (0);
}