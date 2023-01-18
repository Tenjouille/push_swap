/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:29:16 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/18 11:48:38 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_order(t_list *lst)
{
	int		min;
	t_list	*current;

	if (!lst)
		return (0);
	min = lst->nb;
	while (lst->next)
	{
		current = lst->next;
		while (current)
		{
			if (current->nb < min)
				return (0);
			current = current->next;
		}
		lst = lst->next;
		min = lst->nb;
	}
	return (1);
}

int	ft_check_rev_order(t_list *lst)
{
	int		max;
	t_list	*current;

	if (!lst)
		return (0);
	max = lst->nb;
	while (lst->next)
	{
		current = lst->next;
		while (current)
		{
			if (current->nb > max)
				return (0);
			current = current->next;
		}
		lst = lst->next;
		max = lst->nb;
	}
	return (1);
}