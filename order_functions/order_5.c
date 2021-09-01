/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:54:16 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 04:02:52 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    order_3(t_ps *swap)
{
    if ((swap->a[0] > swap->a[1] && swap->a[0] < swap->a[2]) ||
        (swap->a[1] > swap->a[0] && swap->a[1] < swap->a[2]))
        swap_sa(swap);
    else if ((swap->a[0] > swap->a[1] && swap->a[0] > swap->a[2]) ||
        (swap->a[1] > swap->a[0] && swap->a[1] > swap->a[2]))
        swap_ra(swap);
}

void    order_4(t_ps *swap)
{
    if (swap->countb == 0 || swap->ac - 1 + swap->countb == 5)
    {
        if (swap->a[0] < swap->a[1] && swap->a[0] < swap->a[2] && swap->a[0] < swap->a[3])
            swap_pb(swap);
        else if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[2] && swap->a[0] < swap->a[3])
            swap_sa(swap);
        else if (swap->a[1] < swap->a[0] && swap->a[1] < swap->a[2] && swap->a[1] < swap->a[3])
            swap_ra(swap);
        else if (swap->a[2] < swap->a[0] && swap->a[2] < swap->a[1] && swap->a[2] < swap->a[3])
            swap_rra(swap);
        else if (swap->a[3] < swap->a[0] && swap->a[3] < swap->a[1] && swap->a[3] < swap->a[2])
            swap_rra(swap);
    }
    else if (order_verify_a(swap))
        order_3(swap);
    else
        swap_pa(swap);
}

void    order(t_ps *swap)
{
    if (swap->a[0] < swap->a[1] && swap->a[0] < swap->a[2] && swap->a[0] < swap->a[3] &&
        swap->a[0] < swap->a[4])
        swap_pb(swap);
    else if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[2] && swap->a[0] < swap->a[3] &&
        swap->a[0] < swap->a[4])
        swap_sa(swap);
    else if (swap->a[1] < swap->a[0] && swap->a[1] < swap->a[2] && swap->a[1] < swap->a[3] &&
        swap->a[1] < swap->a[4])
        swap_ra(swap);
    else if (swap->a[2] < swap->a[0] && swap->a[2] < swap->a[1] && swap->a[2] < swap->a[3] &&
        swap->a[2] < swap->a[4])
        swap_ra(swap);
    else if (swap->a[3] < swap->a[0] && swap->a[3] < swap->a[1] && swap->a[3] < swap->a[2] &&
        swap->a[3] < swap->a[4])
        swap_rra(swap);
    else if (swap->a[4] < swap->a[0] && swap->a[4] < swap->a[1] && swap->a[4] < swap->a[2] &&
        swap->a[4] < swap->a[3])
        swap_rra(swap);
}

void    order_5(t_ps *swap)
{
    if (swap->countb == 0)
    {
        order(swap);
    }
    else if (swap->countb == 1)
        order_4(swap);
    else if (order_verify_a(swap))
        order_3(swap);
    else
    {
        swap_pa(swap);
        swap_pa(swap);
    }
    
}

void    order_5_or_less(t_ps *swap)
{
    if (swap->ac - 1 == 2)
        swap_sa(swap);
    else if (swap->ac - 1 == 3 && swap->countb == 0)
        order_3(swap);
    else if (swap->ac - 1 == 4 || swap->ac - 1 + swap->countb == 4)
        order_4(swap);
    else if (swap->ac - 1 == 5 || swap->ac - 1 + swap->countb == 5)
        order_5(swap);
}
