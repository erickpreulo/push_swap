/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_verify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 04:20:40 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 04:22:14 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len_ponteiro(char **str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int	order_verify(t_ps *swap)
{
	int		i;

	i = 0;
	if (swap->countb > 0)
		return (1);
	while (i < swap->ac - 2)
	{
		if ((swap->a[i] > swap->a[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	order_verify_a(t_ps *swap)
{
	int		i;

	i = 0;
	while (i < swap->ac - 2)
	{
		if ((swap->a[i] > swap->a[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	order_verify_b(t_ps *swap)
{
	int		i;

	i = 0;
	while (i < swap->countb)
	{
		if ((swap->b[i] < swap->b[i + 1]))
			return (1);
		i++;
	}
	return (0);
}
