/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:27:49 by egomes            #+#    #+#             */
/*   Updated: 2021/08/05 13:32:32 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>

typedef struct	s_ps
{
	int ac;
	int *a;
	int *b;
	char **av;
}				t_ps;

void    ft_putnbr(int nb);
void    ft_putchar(char c);
int	ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);

#endif