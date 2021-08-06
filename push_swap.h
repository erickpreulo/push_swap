/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:27:49 by egomes            #+#    #+#             */
/*   Updated: 2021/08/06 22:04:17 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_ps
{
	int ac;
	int *a;
	int *b;
	char **av;
	int i;
	int j;
}				t_ps;

void    ft_putnbr(int nb);
void    ft_putchar(char c);
int	ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void    swap_sa(t_ps *swap);
void    swap_ra(t_ps *swap);
void    swap_rra(t_ps *swap);
int		validation(t_ps *swap);

#endif