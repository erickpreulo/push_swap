/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 03:35:02 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 03:48:58 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    changeorder_a(t_ps *swap)
{
    int buf[3000];
    int i;

    i = 0;
    while (i < swap->ac)
    {
        buf[i] = swap->a[i];
        i++;
    }
    buf[i] = 0;
    i = 0;
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