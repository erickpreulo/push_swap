/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 14:00:18 by egomes            #+#    #+#             */
/*   Updated: 2021/08/10 22:22:54 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_sb(t_ps *swap)
{ 
    if (swap->find_v)
        ft_putstr("sb\n");
    swap->i = swap->b[0];
    swap->b[0] = swap->b[1];
    swap->b[1] = swap->i;
    if (swap->find_v)
        print_array(swap);
    save_commands(swap, "sb\n");
}

void    swap_rb(t_ps *swap)
{
    int ac;
    int i;
    int *buf;

    if (swap->find_v)
        ft_putstr("rb\n");
    buf = nbrcpyb(swap);
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
    if (swap->find_v)
        print_array(swap);
    save_commands(swap, "rb\n");
    free(buf);
}

int     *nbrcpyb(t_ps *swap)
{
    int i;
    int *buf;

    i = 0;
    buf = malloc(swap->countb);
    while (i < swap->countb)
    {
        buf[i] = swap->b[i];
        i++;
    }
    buf[i] = 0;
    return (buf);
}

void    swap_rrb(t_ps *swap)
{
    int ac;
    int i;
    int *buf;

    if (swap->find_v)
        ft_putstr("rrb\n");
    buf = nbrcpyb(swap);
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
    if (swap->find_v)
        print_array(swap);
    save_commands(swap, "rrb\n");
    free(buf);
}

void    changeorder_b(t_ps *swap)
{
    int *buf;

    buf = nbrcpyb(swap);
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
        ft_putstr("pb\n");
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
        ft_putstr("rrr\n");
    swap_rra(swap);
    swap_rrb(swap);
    save_commands(swap, "rrr\n");
}

void    swap_ss(t_ps *swap)
{
    if (swap->find_v)
        ft_putstr("ss\n");
    swap_sa(swap);
    swap_sb(swap);
    save_commands(swap, "ss\n");
}

void    swap_rr(t_ps *swap)
{
    if (swap->find_v)
        ft_putstr("rr\n");
    swap_ra(swap);
    swap_rb(swap);
    save_commands(swap, "rr\n");
}
