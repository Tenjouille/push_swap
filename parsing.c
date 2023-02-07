/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:54:30 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/07 18:15:53 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		i++;
		sign = -sign;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' )
			return (2147483648);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_micro_parsing(char *str)
{
	int		i;
	int		count;
	long	nb;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != '+' && str[i] != '-')
			return (0);
		if (str[i] == '0')
			count++;
		i++;
	}
	if (i - count > 10)
		return (0);
	if (str[i - 1] == '-' || str[i - 1] == '+')
		return (0);
	nb = ft_atol(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}

int	ft_parsing(int ac, char **av)
{
	int		i;
	int		j;

	j = 0;
	i = ac;
	while (--i > 0)
		if (!ft_micro_parsing(av[++j]))
			return (write(2, "Error\n", 6), 0);
	i = ac;
	while (--i > 0)
	{
		j = i;
		while (--j > 0)
			if (ft_atol(av[j]) == ft_atol(av[i]))
				return (write(2, "Error\n", 6), 0);
	}
	return (1);
}
