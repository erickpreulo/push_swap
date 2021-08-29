/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:27:49 by egomes            #+#    #+#             */
/*   Updated: 2021/08/29 05:10:30 by egomes           ###   ########.fr       */
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
	int b[600];
	char **av;
	int i;
	int j;
	int isa;
	int isb;
	int bsize;
	int size;
	int save;
	int cpyac;
	int countb;
	int changeb;
	int changea;
	int find_v;
	char *commands[100000];
	int	countcomm;
	int ss;
	int rr;
	int rrr;
	int protection;
	int	protectionrb;
	int protectionrrb;
	int median;
	int saveup;
	int savedown;
	int inversea;
	int sortlow;
	int sortsecondlow;
	int sorthigh;
	int sortsecondhigh;
	int less_ra;
	int second_less_ra;
    int less_rra;
    int second_less_rra;
	int	count_second_less;
	int	count_second_high;
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
int		order_verify_a(t_ps *swap);
int		order_verify_b(t_ps *swap);
void	print_array(t_ps *swap);
void	save_commands(t_ps *swap, char *str);
void    print(int *nbr);
void	magic_form(t_ps *swap);
void    magic_5_or_less(t_ps *swap);
int    find_median(t_ps *swap);
int     less_stack_position_rra(t_ps *swap);
int     less_stack_position_ra(t_ps *swap);
int		find_stack(t_ps *swap);
int     sort_b_low(t_ps *swap);
int     sort_b_high(t_ps *swap);
void    find_less_nbr(t_ps *swap);
int     sort_a_low(t_ps *swap);
int     sort_a_second_low(t_ps *swap);
void    bether_choice_low_ra(t_ps *swap);
void    bether_choice_second_low_ra(t_ps *swap);
void    bether_choice_low_rra(t_ps *swap);
void    bether_choice_second_low_rra(t_ps *swap);
void    bether_choice_ra_rra(t_ps *swap);
void    the_choice(t_ps *swap);
int     sort_a_high(t_ps *swap);
int     sort_a_second_high(t_ps *swap);
#endif