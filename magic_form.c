/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:50:29 by egomes            #+#    #+#             */
/*   Updated: 2021/08/26 02:06:48 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    find_median(t_ps *swap)
{
    int i;
    int j;

    i = 0;
    while (i <= swap->ac - 2)
    {
        swap->saveup = 0;
        swap->savedown = 0;
        j = 0;
        while (j <= swap->ac - 2)
        {
            if (swap->a[i] > swap->a[j])
                swap->saveup++;
            if (swap->a[i] < swap->a[j])
                swap->savedown++;
            if (swap->saveup == (swap->ac - 2) / 2 && swap->savedown == ((swap->ac - 2) / 2))
                return (swap->a[i]);
            j++;
        }
        i++;
    }
    return (0);
}

int     less_stack_position_ra(t_ps *swap)
{
    int i;

    i = 0;
    while (i <= (swap->ac - 2) / 2)
    {
        if (swap->a[i] < swap->stack)
            return (1);
        i++;
    }
    return (0);
}

int     less_stack_position_rra(t_ps *swap)
{
    int i;

    i = swap->ac - 1;
    while (i >= (swap->ac - 2) / 2)
    {
        if (swap->a[i] <= swap->stack)
            return (1);
        i--;
    }
    return (0);
}

void    order_b(t_ps *swap)
{
    if (order_verify_b(swap))
    {
        if (swap->b[0] < swap->b[1] && swap->b[0] > swap->b[swap->bsize] && swap->a[1] <= swap->stack && swap->a[2] > swap->stack)
            swap_ss(swap);
        else if (swap->b[0] < swap->b[1] && swap->b[0] > swap->b[swap->bsize])
            swap_sb(swap);
        else if (swap->b[0] < swap->b[1] && swap->b[0] < swap->b[swap->bsize] && less_stack_position_ra(swap))
            swap_rr(swap);
        else if (swap->b[0] < swap->b[1] && swap->b[0] < swap->b[swap->bsize])
            swap_rb(swap);
        else if (swap->b[swap->bsize] > swap->b[0] && less_stack_position_rra(swap))
            swap_rrr(swap);
        else if (swap->b[swap->bsize] > swap->b[0])
            swap_rb(swap);
    }
}

void    pass_to_b(t_ps *swap)
{
    int i;
    int j;

    while (swap->countb < swap->median)
    {

        if ((swap->a[0] <= swap->stack && swap->saveup == swap->savedown) ||
            (swap->a[0] < swap->stack && swap->saveup != swap->savedown)) // preciso resolver isto!!
        {
            if (swap->a[0] < swap->b[0] && swap->a[0] < swap->b[1] && swap->a[0] > swap->b[swap->bsize])
            {
                i = 0;
                while (swap->a[0] < swap->b[0])
                {
                    swap_rb(swap);
                    i++;
                }
                swap_pb(swap);
                j = 0;
                while (j <= i)
                {
                    swap_rrb(swap);
                    j++;
                }
            }
            else
                swap_pb(swap);
            if (swap->countb > 1)
                order_b(swap);
        }
        else if (swap->a[1] <= swap->stack && swap->a[2] > swap->stack)
            swap_sa(swap);
        else if (less_stack_position_ra(swap))
            swap_ra(swap);
        else if (less_stack_position_rra(swap))
            swap_rra(swap);
    }
}

void    order_a(t_ps *swap)
{
    if (swap->protection > 70)
    {
        printf("mais de 50 tentativas\n");
        exit(0);
    }
    if (order_verify_a(swap))
    {
        swap->protection++;
        if (swap->a[0] > swap->a[1] && swap->a[0] < swap->a[swap->ac - 2])
            swap_sa(swap);
        else if (swap->a[0] > swap->a[1] && swap->a[0] > swap->a[swap->ac - 2])
            swap_ra(swap);
        else if (swap->a[0] < swap->a[1] && swap->a[0] > swap->a[swap->ac - 2])
            swap_rra(swap);
        else if (swap->inversea != 0)
        {
            swap_pa(swap);
            swap->inversea--;
        }
        else
            swap_pb(swap);
        order_a(swap);
    }
}

void    magic_100_or_less(t_ps *swap)
{
    int i;

    i = 0;
    pass_to_b(swap);
    order_a(swap);
    while (i <= swap->savedown)
    {
        swap_pa(swap);
        i++;
    }
}

void	magic_form(t_ps *swap)
{
	if (order_verify(swap))
	{
        if (swap->ac - 1 + swap->countb <= 5)
            magic_5_or_less(swap);
        else if (swap->ac - 1 >= 5 && swap->ac - 1 <= 100)
            magic_100_or_less(swap);
		magic_form(swap);
	}
}
