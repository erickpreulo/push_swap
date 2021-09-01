/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:50:29 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 04:06:53 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pass_to_b_100(t_ps *swap)
{
	while (swap->ac - 2 >= 0)
	{
		if (swap->countstack == 0)
			sort_a_last_stack_100(swap);
		if (swap->ac - 2 < 10)
			swap_pb(swap);
		else if (swap->a[0] < swap->sortlaststack)
		{
			swap_pb(swap);
			swap->countstack++;
			if (swap->countstack == 9)
				swap->countstack = 0;
		}
		else if (swap->a[1] < swap->sortlaststack)
			swap_sa(swap);
		else if (less_stack_position_ra(swap))
			swap_ra(swap);
		else
			swap_rra(swap);
	}
}

void	pass_to_b_500(t_ps *swap)
{
	while (swap->ac - 2 >= 0)
	{
		if (swap->ac - 2 < 50)
			swap_pb(swap);
		if (swap->countstack == 0)
			sort_a_last_stack_500(swap);
		if (swap->a[0] < swap->sortlaststack)
		{
			swap_pb(swap);
			swap->countstack++;
			if (swap->countstack == 49)
				swap->countstack = 0;
		}
		else if (swap->a[1] < swap->sortlaststack)
			swap_sa(swap);
		else if (less_stack_position_ra(swap))
			swap_ra(swap);
		else
			swap_rra(swap);
	}
}

void	pass_to_a(t_ps *swap)
{
	while (swap->bsize >= 0)
	{
		if (swap->b[0] == sort_b_high(swap))
			swap_pa(swap);
		else if (less_stack_position_rb(swap))
			swap_rb(swap);
		else
			swap_rrb(swap);
	}
}

void	order_else(t_ps *swap)
{
	if (swap->ac - 1 + swap->countb <= 110)
		pass_to_b_100(swap);
	else
		pass_to_b_500(swap);
	pass_to_a(swap);
}

void	order_form(t_ps *swap)
{
	if (order_verify(swap))
	{
		if (swap->ac - 1 + swap->countb <= 5)
			order_5_or_less(swap);
		else
			order_else(swap);
		order_form(swap);
	}
}
