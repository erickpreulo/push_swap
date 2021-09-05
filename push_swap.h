/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 12:27:49 by egomes            #+#    #+#             */
/*   Updated: 2021/09/05 05:12:21 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_ps
{
	char	*commands[100000];
	char	**av;
	int		a[1000];
	int		b[1000];
	int		ac;
	int		i;
	int		j;
	int		ss;
	int		rr;
	int		rrr;
	int		isa;
	int		isb;
	int		bsize;
	int		size;
	int		cpyac;
	int		countb;
	int		changeb;
	int		changea;
	int		find_v;
	int		countcomm;
	int		sortlow;
	int		sortbhigh;
	int		sortlaststack;
	int		countstack;
	int		size_stack;
	int		less_size_stack;
	int		x;
}				t_ps;

		// SRC
void	ft_putchar(char c);
void	ft_putnbr(long int nb);
int		ft_atoi(const char *str);
int		ft_strlen(char *str);
int		ft_len_ponteiro(char **str);
void	ft_putstr(char *str);

		// validation
int		validation(t_ps *swap);

		// -v command. Can see what happen
void	find_v(char *str, t_ps *swap);
void	change_av(t_ps *swap);

		// commands
void	swap_sa(t_ps *swap);
void	swap_sb(t_ps *swap);
void	swap_ss(t_ps *swap);
void	swap_ra(t_ps *swap);
void	swap_rb(t_ps *swap);
void	swap_rr(t_ps *swap);
void	swap_rra(t_ps *swap);
void	swap_rrb(t_ps *swap);
void	swap_rrr(t_ps *swap);
void	swap_pa(t_ps *swap);
void	swap_pb(t_ps *swap);

		// order verify
int		order_verify(t_ps *swap);
int		order_verify_a(t_ps *swap);
int		order_verify_b(t_ps *swap);

		// put the array in order
void	order_form(t_ps *swap);
void	order_5_or_less(t_ps *swap);
int		sort_b_high(t_ps *swap);
int		less_stack_position_ra(t_ps *swap);
int		less_stack_position_rb(t_ps *swap);
int		sort_a_last_stack_100(t_ps *swap);
int		sort_a_last_stack_500(t_ps *swap);
void	pass_to_b_100(t_ps *swap);
void	pass_to_b_500(t_ps *swap);

		// print
void	print(int *nbr);
void	print_array(t_ps *swap);
void	print_commands(t_ps *swap);
void	save_commands(t_ps *swap, char *str);
#endif