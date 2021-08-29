/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:50:29 by egomes            #+#    #+#             */
/*   Updated: 2021/08/29 05:07:39 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void    order_b(t_ps *swap)
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
}*/

void    pass_to_b(t_ps *swap)
{
    while (swap->ac - 2 >= 0)
    {
        if ((swap->a[0] == sort_a_second_low(swap) && swap->count_second_less == 0) || swap->a[0] == sort_a_low(swap) ||
            (swap->a[0] == sort_a_high(swap) && swap->bsize > 0))
        {
            if (swap->a[0] == swap->sortlow)
                swap->count_second_less = 0;
            else
                swap->count_second_less = 1;
            swap_pb(swap);
            if (swap->b[0] == swap->sorthigh)
                swap_rb(swap);
            else if (swap->b[0] < swap->b[1])
                swap_sb(swap);
        }
        else if (swap->a[1] == swap->sortlow)
            swap_sa(swap);
        else if (less_stack_position_ra(swap))
            swap_ra(swap);
        else
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
        else
            swap_sa(swap);
        order_a(swap);
    }
}

void    pass_to_a(t_ps *swap)
{
    while (swap->countb > 0)
    {
        if (swap->b[0] == sort_b_high(swap))
        {
            swap_pa(swap);
            order_a(swap);
        }
        else if (swap->b[0] < swap->b[swap->bsize])
            swap_rrb(swap);
    }
}

void    magic_100_or_less(t_ps *swap)
{
    pass_to_b(swap);
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
