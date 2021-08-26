/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:33:03 by egomes            #+#    #+#             */
/*   Updated: 2021/08/26 01:09:23 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
        ft_putchar(nb + '0');
}

int	ft_atoi(const char *str)
{
	long int	neg;
	long int	i;
	long int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void    print(int *nbr)
{
    int i;

    i = 0;
    while (i <= 8)
    {
        ft_putnbr(nbr[i]);
        i++;
    }
}

int		order_verify(t_ps *swap)
{
	int i;

	i = 0;
	if (swap->countb > 0)
		return (1);
	while (i < swap->ac - 2)
	{
		if ((swap->a[i] > swap->a[i + 1]))
			return(1);
		i++;
	}
	return (0);
}

int		order_verify_a(t_ps *swap)
{
	int i;

	if (swap->inversea != 0)
		return (1);
	i = 0;
	while (i < swap->ac - 2)
	{
		if ((swap->a[i] > swap->a[i + 1]))
			return(1);
		i++;
	}
	return (0);
}

int		order_verify_b(t_ps *swap)
{
	int i;

	i = 0;
	while (i < swap->countb)
	{
		if ((swap->b[i] < swap->b[i + 1]))
			return(1);
		i++;
	}
	return (0);
}
