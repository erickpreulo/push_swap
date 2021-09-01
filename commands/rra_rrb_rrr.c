/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 03:34:26 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 03:48:59 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_rra(t_ps *swap)
{
    int ac;
    int i;
    int buf[3000];

    if (swap->find_v && !(swap->rrr))
        ft_putstr("\nrra\n");
    i = 0;
    while (i < swap->ac)
    {
        buf[i] = swap->a[i];
        i++;
    }
    buf[i] = 0;
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
