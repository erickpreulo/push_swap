/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:27:49 by egomes            #+#    #+#             */
/*   Updated: 2021/08/10 21:24:46 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_ps
{
	int ac;
	int *a;
	int b[1000];
	char **av;
	int i;
	int j;
	int isa;
	int isb;
	int bsize;
	int size;
	int save;
	int countb;
	int changeb;
	int changea;
	int find_v;
	char *commands[5000];
	int	countcomm;
}				t_ps;

void    ft_putnbr(int nb);
void    ft_putchar(char c);
int	ft_atoi(const char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
void    swap_sa(t_ps *swap);
void    swap_sb(t_ps *swap);
void	swap_ss(t_ps *swap);
void    swap_ra(t_ps *swap);
void    swap_rb(t_ps *swap);
void    swap_rr(t_ps *swap);
void    swap_rra(t_ps *swap);
void    swap_rrb(t_ps *swap);
void    swap_rrr(t_ps *swap);
void    swap_pa(t_ps *swap);
void    swap_pb(t_ps *swap);
int		validation(t_ps *swap);
int		ft_strlennbr(int *str);
char	*ft_itoa(int n);
int     *nbrcpya(t_ps *swap);
int     *nbrcpyb(t_ps *swap);
int		order_verify(t_ps *swap);
void	print_array(t_ps *swap);
void	save_commands(t_ps *swap, char *str);
void    print(int *nbr);

#endif