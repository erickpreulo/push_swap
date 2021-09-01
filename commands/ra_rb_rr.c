/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 03:33:29 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 03:49:01 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_ra(t_ps *swap)
{
    int ac;
    int i;
    int buf[3000];

    if (swap->find_v && !(swap->rr))
        ft_putstr("\nra\n");
    i = 0;
    while (i < swap->ac)
    {
        buf[i] = swap->a[i];
        i++;
    }
    buf[i] = 0;
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
    if (swap->find_v && !(swap->rr))
        print_array(swap);
    if (!swap->rr)
        save_commands(swap, "ra\n");
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
