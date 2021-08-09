/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:26:01 by egomes            #+#    #+#             */
/*   Updated: 2021/08/09 20:42:03 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print(int *nbr)
{
    int i;

    i = 0;
    while (i <= 8)
    {
        ft_putnbr(nbr[i]);
        i++;
    }
}

void    swap_sa(t_ps *swap)
{
    ft_putstr("sa\n");
    swap->i = swap->a[0];
    swap->a[0] = swap->a[1];
    swap->a[1] = swap->i;
}

void    swap_ra(t_ps *swap)
{
    int ac;
    int i;
    int *buf;

    ft_putstr("ra\n");
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

void    swap_rb(t_ps *swap)
{
    int ac;
    int i;
    int *buf;

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
    free(buf);
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

    ft_putstr("rra\n");
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
    free(buf);
}

void    less_a(t_ps *swap)
{
    int i;

    i = 0;
    swap->save = swap->a[0];
    while (i <= swap->ac - 3)
    {
        swap->a[i] = swap->a[i + 1];
        i++;
    }
    swap->ac--;
}

void    take_a(t_ps *swap, int *b)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (!(swap->size == 0))
    {
        b[i] = swap->save;
        i++;
    }
    while (j <= swap->bsize + 1)
        b[i++] = swap->a[j++];
}

void    changeorder(t_ps *swap)
{
    int *buf;

    buf = nbrcpyb(swap);
    if (swap->countb == 0)
        swap->b[swap->countb] = swap->a[0];
    else
    {
        swap->i = 1;
        while (swap->i <= swap->count)
        {
            swap->b[swap->i] = buf[swap->i - 1];
            swap->i++;
        }
        swap->b[0] = swap->a[0];
    }
    swap->count++;
}

void    swap_pb(t_ps *swap)
{
    ft_putstr("pb\n");
    changeorder(swap);
    swap->countb++;
    swap->isb = 1;
    swap->bsize = swap->size;
    swap->size++;
    less_a(swap);
}
/*
    int i;
    int cpy;

    i = 0;
    cpy = swap->bsize;
    while (i <= swap->bsize / 2)
    {
        swap->j = swap->b[i];
        swap->b[i] = swap->b[cpy];
        swap->b[cpy] = swap->j;
        i++;
        cpy++;
    }*/
