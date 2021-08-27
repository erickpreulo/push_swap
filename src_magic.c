/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_magic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 00:19:54 by egomes            #+#    #+#             */
/*   Updated: 2021/08/27 22:57:36 by egomes           ###   ########.fr       */
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
    int cpy;

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
                cpy = swap->a[i];
                swap->sortsecondlow = cpy;
                return (cpy);
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
            swap->savedown = swap->ac - 5;
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

