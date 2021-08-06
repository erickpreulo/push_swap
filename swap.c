/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 15:26:01 by egomes            #+#    #+#             */
/*   Updated: 2021/08/06 22:05:23 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_sa(t_ps *swap)
{
    swap->i = swap->a[0];
    swap->a[0] = swap->a[1];
    swap->a[1] = swap->i;
}

void    swap_ra(t_ps *swap)
{
    int ac;

    ac = swap->ac - 2;
    swap->j = 0;
    while (swap->j != swap->ac / 2)
    {
        swap->i = swap->a[swap->j];
        swap->a[swap->j] = swap->a[ac];
        swap->a[ac] = swap->i;
        swap->j++;
        ac--;
    }
}

int     *nbrcpy(t_ps *swap)
{
    int i;
    int *buf;

    i = 0;
    buf = malloc(swap->ac - 1);
    while (swap->a[i] != 0)
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

    buf = nbrcpy(swap);
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