/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:54:30 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/09 17:27:37 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_micro_parsing(char *str)
{
	int		i;
	long	nb;

	i = 0;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	if (str[i - 1] == '-' || str[i - 1] == '+')
		return (0);
	nb = ft_atol(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}
