/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:00:18 by egomes            #+#    #+#             */
/*   Updated: 2021/08/27 19:34:21 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_sb(t_ps *swap)
{ 
    if (swap->find_v && !(swap->ss))
        ft_putstr("\nsb\n");
    swap->i = swap->b[0];
    swap->b[0] = swap->b[1];
    swap->b[1] = swap->i;
    if (swap->find_v && !(swap->ss))
        print_array(swap);
    if (!swap->ss)
        save_commands(swap, "sb\n");
}

void    swap_rb(t_ps *swap)
{
    int ac;
    int i;
    int buf[3000];

    if (swap->find_v && !(swap->rr))
        ft_putstr("\nrb\n");
    i = 0;
    while (i < swap->countb)
    {
        buf[i] = swap->b[i];
        i++;
    }
    buf[i] = 0;
    ac = swap->countb - 1;
    swap->j = 0;
    swap->i = swap->b[0];
    while(swap->j < ac)
    {
        i = swap->b[swap->j + 1];
        swap->b[swap->j] = i;
        swap->j++;
    }
    swap->b[ac] = swap->i;
    if (swap->find_v && !(swap->rr))
        print_array(swap);
    if (!swap->rr)
        save_commands(swap, "rb\n");
}

void    swap_rrb(t_ps *swap)
{
    int ac;
    int i;
    int buf[3000];

    if (swap->find_v && !(swap->rrr))
        ft_putstr("\nrrb\n");
    i = 0;
    while (i < swap->countb)
    {
        buf[i] = swap->b[i];
        i++;
    }
    buf[i] = 0;
    ac = swap->bsize;
    swap->j = 1;
    swap->i = swap->b[ac];
    while(swap->j <= ac)
    {
        i = buf[swap->j - 1];
        swap->b[swap->j] = i;
        swap->j++;
    }
    swap->b[0] = swap->i;
    if (swap->find_v && !(swap->rrr))
        print_array(swap);
    if (!swap->rrr)
        save_commands(swap, "rrb\n");
}

void    changeorder_b(t_ps *swap)
{
    int buf[3000];
    int i;

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

void    less_a(t_ps *swap)
{
    int i;

    i = 0;
    while (i <= swap->ac - 3)
    {
        swap->a[i] = swap->a[i + 1];
        i++;
    }
    swap->ac--;
}

void    swap_pb(t_ps *swap)
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

void    swap_rrr(t_ps *swap)
{
    if (swap->find_v)
        ft_putstr("\nrrr\n");
    swap->rrr = 1;
    swap_rra(swap);
    swap_rrb(swap);
    if (swap->find_v)
        print_array(swap);
    save_commands(swap, "rrr\n");
}

void    swap_ss(t_ps *swap)
{
    if (swap->find_v)
        ft_putstr("\nss\n");
    swap->ss = 1;
    swap_sa(swap);
    swap_sb(swap);
    if (swap->find_v)
        print_array(swap);
    save_commands(swap, "ss\n");
}

void    swap_rr(t_ps *swap)
{
    if (swap->find_v)
        ft_putstr("\nrr\n");
    swap->rr = 1;
    swap_ra(swap);
    swap_rb(swap);
    if (swap->find_v)
        print_array(swap);
    save_commands(swap, "rr\n");
}
