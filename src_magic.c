/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_magic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 00:19:54 by egomes            #+#    #+#             */
/*   Updated: 2021/08/27 19:20:13 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     sort_b_low(t_ps *swap)
{
    int i;
    int j;
    int size;

    i = 0;
    j = 0;
    size = 0;
    if (swap->bsize == 0)
        return (swap->b[0]);
    while (i <= swap->bsize)
    {
        while (j <= swap->bsize)
        {
            if (swap->b[i] <= swap->b[j])
                size++;
            if (size == swap->bsize)
                return (swap->b[i]);
        }
    }
    return (0);
}

void     find_less_nbr(t_ps *swap)
{
    int i;

    i = 0;
    while (i <= swap->bsize)
    {
        if (swap->a[0] < swap->b[i] && i < swap->bsize / 2)
        {
            swap_rb(swap);
            swap->protectionrb++;
            break;
        }
        else if (swap->a[0] < swap->b[i])
        {
            swap_rrb(swap);
            swap->protectionrrb++;
            break;
        }
        i++;
    }
}

void    find_less_nbr_1(t_ps *swap)
{
    int i;
    int j;

    
    j = swap->bsize;
    i = 0;
    while (i < swap->bsize / 2)
    {
        if (swap->a[0] < sort_b_low(swap) && i < swap->bsize / 2)
        {
            swap_rrb(swap);
            swap->protectionrrb++;
            break;
        }
        else if (swap->a[0] < sort_b_low(swap))
        {
            swap_rb(swap);
            swap->protectionrb++;
            break;
        }
        i++;
        j--;
    }
}

int     sort_b_high(t_ps *swap)
{
    int i;
    int j;
    int size;

    i = 0;
    size = 0;
    if (swap->bsize == 0)
        return (swap->b[0]);
    while (i <= swap->bsize)
    {
        j = 0;
        while (j <= swap->bsize)
        {
            if (swap->b[i] >= swap->b[j])
                size++;
            if (size == swap->bsize)
                return (swap->b[i]);
            j++;
        }
        i++;
    }
    return (0);
}

int     sort_a_low(t_ps *swap)
{
    int i;
    int j;
    int size;

    i = 0;
    while (i <= swap->ac - 1)
    {
        j = 0;
        size = 0;
        while (j <= swap->ac - 1)
        {
            if (swap->a[i] <= swap->a[j])
                size++;
            if (size == swap->ac - 1)
            {
                swap->sortlow = swap->a[i];
                return (swap->sortlow);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int     sort_a_second_low(t_ps *swap)
{
    int i;
    int j;
    int size;

    i = 0;
    while (i <= swap->ac - 1)
    {
        j = 0;
        size = 0;
        while (j <= swap->ac - 1)
        {
            if (swap->a[i] <= swap->a[j])
                size++;
            if (size == swap->ac - 2)
            {
                swap->sortsecondlow = swap->a[i];
                return (swap->sortsecondlow);
            }
            j++;
        }
        i++;
    }
    return (0);
}

int    find_stack(t_ps *swap)
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
            if (swap->a[i] >= swap->a[j])
                swap->saveup++;
            j++;
        }
        if (swap->saveup == 2)
        {
            swap->savedown = swap->ac - 4;
            return (swap->a[i]);
        }
        i++;
    }
    return (0);
}

int     less_stack_position_ra(t_ps *swap)
{
    int i;

    i = 0;
    while (i <= swap->ac - 2)
    {
        if (swap->a[i] == swap->sortlow && i <= (swap->ac - 2) / 2)
            return (1);
        i++;
    }
    return (0);
}

int     less_stack_position_rra(t_ps *swap)
{
    int i;

    i = (swap->ac - 2) / 2;
    while (i <= swap->ac - 2)
    {
        if (swap->a[i] == swap->sortlow)
            return (1);
        i++;
    }
    return (0);
}

