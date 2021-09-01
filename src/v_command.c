/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 04:13:48 by egomes            #+#    #+#             */
/*   Updated: 2021/09/01 04:15:08 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_v(char *str, t_ps *swap)
{
	if (str[0] == '-' && str[1] == 'v' && str[2] == '\0')
		swap->find_v = 1;
}

void	change_av(t_ps *swap)
{
	int		i;

	i = 0;
	while (i < swap->ac)
	{
		swap->av[i] = swap->av[i + 1];
		i++;
	}
	swap->ac -= 1;
}
