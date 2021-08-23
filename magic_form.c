/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:50:29 by egomes            #+#    #+#             */
/*   Updated: 2021/08/23 17:47:38 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    magic_3(t_ps *swap)
{
    printf("OOO\n");
    if ((swap->a[0] > swap->a[1] && swap->a[0] < swap->a[2]) ||
        (swap->a[1] > swap->a[0] && swap->a[1] < swap->a[2]))
        swap_sa(swap);
    else if ((swap->a[0] > swap->a[1] && swap->a[0] > swap->a[2]) ||
        (swap->a[1] > swap->a[0] && swap->a[1] > swap->a[2]))
        swap_ra(swap);
}

void    magic_4(t_ps *swap)
{
    if (swap->bsize == 0)
    {
        if (swap->a[0] < swap->a[1] && swap->a[0] < swap->a[2] && swap->a[0] < swap->a[3])
            swap_pb(swap);
        else if (swap->a[1] < swap->a[0] && swap->a[1] < swap->a[2] && swap->a[1] < swap->a[3])
            swap_ra(swap);
        else if (swap->a[2] < swap->a[0] && swap->a[2] < swap->a[1] && swap->a[2] < swap->a[3])
            swap_rra(swap);
        else if (swap->a[3] < swap->a[0] && swap->a[3] < swap->a[1] && swap->a[3] < swap->a[2])
            swap_rra(swap);
    }
    else if (order_verify_a(swap))
        magic_3(swap);
    else
        swap_pa(swap);
}

/*void    magic_5(t_ps *swap)
{

}
*/
void    magic_5_or_less(t_ps *swap)
{
    if (swap->ac - 1 == 2)
        swap_sa(swap);
    else if (swap->ac - 1 == 3)
        magic_3(swap);
    else if (swap->ac - 1 == 4)
        magic_4(swap);
    /*else if (swap->ac - 1 == 5)
        magic_5(swap);*/
}

void	magic_form(t_ps *swap)
{
	if (order_verify(swap))
	{
        if (swap->ac - 1 <= 5)
            magic_5_or_less(swap);
		magic_form(swap);
	}
}
