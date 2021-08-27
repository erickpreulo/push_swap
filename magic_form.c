/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:50:29 by egomes            #+#    #+#             */
/*   Updated: 2021/08/27 22:57:43 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    order_b(t_ps *swap)
{
    
    if (order_verify_b(swap))
    {
        if (swap->b[0] < swap->b[1] && swap->b[0] > swap->b[swap->bsize] && swap->a[1] < swap->stack && swap->a[swap->ac - 2] > swap->stack)
            swap_ss(swap);
        else if (swap->b[0] < swap->b[1] && swap->b[0] > swap->b[swap->bsize])
            swap_sb(swap);
        else if (swap->b[0] < swap->b[1] && swap->b[0] < swap->b[swap->bsize] && less_stack_position_ra(swap))
            swap_rr(swap);
        else if (swap->b[0] < swap->b[1] && swap->b[0] < swap->b[swap->bsize])
            swap_rb(swap);
        else if (swap->b[swap->bsize] > swap->b[0] && less_stack_position_rra(swap))
            swap_rrr(swap);
        else if (swap->b[swap->bsize] > swap->b[0] && swap->b[0] > swap->b[1])
            swap_rrb(swap);
        else
            swap_pa(swap);
        order_b(swap);
    }
}

void    pass_to_b(t_ps *swap)
{
    while (swap->countb <= swap->savedown)
    {
        if (swap->a[0] == sort_a_low(swap) || swap->a[0] == sort_a_second_low(swap))
        {
            swap_pb(swap);
            if (swap->countb > 1)
                order_b(swap);
        }
        else if (swap->a[1] == swap->sortlow)
            swap_sa(swap);
        else if (less_stack_position_ra(swap))
            swap_ra(swap);
        else if (less_stack_position_rra(swap))
            swap_rra(swap);
    }
}

void    order_a(t_ps *swap)
{
    if (order_verify_a(swap))
    {
        if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[swap->ac - 2])
            swap_sa(swap);
        else if (swap->a[0] > swap->a[1] && swap->a[0] > swap->a[swap->ac - 2])
            swap_ra(swap);
        else if (swap->a[0] < swap->a[1] && swap->a[0] > swap->a[swap->ac - 2])
            swap_rra(swap);
        else if (swap->a[0] < swap->stack)
        {
            swap_pb(swap);
            swap->inversea++;
        }
        else
            swap_sa(swap);
        order_a(swap);
    }
}

void    pass_to_a(t_ps *swap) //continuar daqui!
{
    while (swap->countb > 0)
    {
        if (swap->b[0] == sort_b_high(swap))
        {
            swap_pa(swap);
            order_a(swap);
        }
        else
            order_b(swap);
        /*if (swap->a[0] > swap->a[1] && swap->b[0] < swap->b[1])
            swap_ss(swap);
        else if (swap->a[0] > swap->a[1])    
            swap_sa(swap);*/
    }
}

void    magic_100_or_less(t_ps *swap)
{
    pass_to_b(swap);
    order_a(swap);
    pass_to_a(swap);
}

void	magic_form(t_ps *swap)
{
	if (order_verify(swap))
	{
        if (swap->ac - 1 + swap->countb <= 5)
            magic_5_or_less(swap);
        else
            magic_100_or_less(swap);
		magic_form(swap);
	}
}
