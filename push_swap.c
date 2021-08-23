/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:08:45 by egomes            #+#    #+#             */
/*   Updated: 2021/08/23 17:05:53 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(t_ps *swap)
{
	int i;

	i = 0;
	swap->i = 0;
	swap->j = 0;
	ft_putstr("stacks\n");
	while ((swap->i <= (swap->ac - 2)) 
		|| ((swap->isb) && swap->j <= swap->bsize))
	{
		if (swap->bsize >= (swap->ac - 1) && i <= swap->bsize - (swap->ac - 1))
		{
			ft_putchar('	');
			i++;
		}
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
	int i;

	i = 0;
	while (i < swap->countcomm)
	{
		ft_putstr(swap->commands[i]);
		i++;
	}
}

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
			magic_form(swap);
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
}

void		find_v(char *str, t_ps *swap)
{
	if (str[0] == '-' && str[1] == 'v' && str[2] == '\0')
		swap->find_v = 1;
}

void	change_av(t_ps *swap)
{
	int i;

	i = 0;
	while (i < swap->ac)
	{
		swap->av[i] = swap->av[i + 1];
		i++;
	}
	swap->ac -= 1;
}

int		main(int ac, char **av)
{
	t_ps swap;
	int a[ac];

	init_struct(&swap);
	swap.ac = ac;
	swap.cpyac = ac;
	swap.a = a;
	swap.av = av;
	find_v(av[1], &swap);
	if (swap.find_v)
		change_av(&swap);
	if (ac < 2)
		ft_putstr("Error\n");
	else
	{
		take_array(&swap);
		if (validation(&swap))
		{
			ft_putstr("Error\n");
			return (0);
		}
		push_swap(&swap);
	}
	print_commands(&swap);
	return (0);
}