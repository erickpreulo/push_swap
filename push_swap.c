/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:08:45 by egomes            #+#    #+#             */
/*   Updated: 2021/08/06 17:59:31 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_ps *swap)
{
	swap_sa(swap);
}

void	takearray(t_ps *swap)
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

void	printarray(t_ps *swap)
{
	swap->i = 0;
	while (swap->i < (swap->ac -1))
	{
		ft_putnbr(swap->a[swap->i]);
		ft_putchar('	');
		if (swap->b[swap->i] != 0) 
			ft_putnbr(swap->b[swap->i]);
		ft_putchar('\n');
		swap->i++;
	}
	ft_putchar('a');
	ft_putstr("	b");
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
			if (swap->a[i] == swap->a[j] || swap->a[i] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
		if (duplicate(&swap))
		{
			ft_putstr("ERROR\n");
			return (0);
		}
		push_swap(&swap);
		printarray(&swap);
	}
	ft_putchar('\n');
	return (0);
}