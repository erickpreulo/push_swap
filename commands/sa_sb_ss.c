/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 03:33:53 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 03:49:00 by egomes           ###   ########.fr       */
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
