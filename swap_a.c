/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:26:01 by egomes            #+#    #+#             */
/*   Updated: 2021/08/23 17:05:36 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_sa(t_ps *swap)
{
    if (swap->find_v && !(swap->ss))
        ft_putstr("\nsa\n");
    swap->i = swap->a[0];
    swap->a[0] = swap->a[1];
    swap->a[1] = swap->i;
    if (swap->find_v && !(swap->ss))
        print_array(swap);
    if (!swap->ss)
        save_commands(swap, "sa\n");
}

void    swap_ra(t_ps *swap)
{
    int ac;
    int i;
    int *buf;

    if (swap->find_v && !(swap->rr))
        ft_putstr("\nra\n");
    buf = nbrcpya(swap);
    ac = swap->ac - 2;
    swap->j = 0;
    swap->i = swap->a[0];
    while(swap->j <= ac)
    {
        i = buf[swap->j + 1];
        swap->a[swap->j] = i;
        swap->j++;
    }
    swap->a[ac] = swap->i;
    free(buf);
    if (swap->find_v && !(swap->rr))
        print_array(swap);
    if (!swap->rr)
        save_commands(swap, "ra\n");
}

int     *nbrcpya(t_ps *swap)
{
    int i;
    int *buf;

    i = 0;
    buf = malloc(swap->ac - 1);
    while (i < swap->ac)
    {
        buf[i] = swap->a[i];
        i++;
    }
    buf[i] = 0;
    return (buf);
}

void    swap_rra(t_ps *swap)
{
    int ac;
    int i;
    int *buf;

    if (swap->find_v && !(swap->rrr))
        ft_putstr("\nrra\n");
    buf = nbrcpya(swap);
    ac = swap->ac - 2;
    swap->j = 1;
    swap->i = swap->a[ac];
    while(swap->j <= ac)
    {
        i = buf[swap->j - 1];
        swap->a[swap->j] = i;
        swap->j++;
    }
    swap->a[0] = swap->i;
    if (swap->find_v && !(swap->rrr))
        print_array(swap);
    if (!swap->rrr)
        save_commands(swap, "rra\n");
    free(buf);
}

void    changeorder_a(t_ps *swap)
{
    int *buf;
    int i;

    i = 0;
    buf = nbrcpya(swap);
    swap->i = 1;
    while (swap->i <= swap->ac - 1)
    {
        swap->a[swap->i] = buf[i];
        swap->i++;
        i++;
    }
    swap->a[0] = swap->b[0];
    swap->changea++;
    swap->ac++;
}

void    less_b(t_ps *swap)
{
    int i;

    i = 0;
    while (i <= swap->bsize)
    {
        swap->b[i] = swap->b[i + 1];
        i++;
    }
    swap->bsize--;
}

void    swap_pa(t_ps *swap)
{
    if (swap->find_v)
        ft_putstr("\npa\n");
    changeorder_a(swap);
    swap->isa = 1;
    less_b(swap);
    swap->countb--;
    if (swap->find_v)
        print_array(swap);
    save_commands(swap, "pa\n");
}
