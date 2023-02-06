/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:29:16 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/04 16:19:58 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_stack *lst)
{
	int	min;

	min = lst->nb;
	while (lst != NULL)
	{
		if (min > lst->nb)
			min = lst->nb;
		lst = lst->next;
	}
	return (min);
}

int	ft_max(t_stack *lst)
{
	int	max;

	max = lst->nb;
	while (lst != NULL)
	{
		if (max < lst->nb)
			max = lst->nb;
		lst = lst->next;
	}
	return (max);
}

void	ft_improve(t_stack **cmd)
{
	t_stack	*cmp;
	t_stack	*cur;
	t_stack	*prev;

	cmp = *cmd;
	while (cmp)
	{
		prev = cmp;
		cur = cmp->next;
		while (cur && cur->nb != PA && cur->nb != PB && cur->nb != 0)
		{
			if (cmp->nb == cur->nb + 1 || cmp->nb == cur->nb - 1)
			{
				cmp->nb = cmp->nb + cur->nb;
				prev->next = ft_lstdelone(cur);
				break ;
			}
			cur = cur->next;
			prev = prev->next;
		}
		cmp = cmp->next;
	}
}

int	ft_check_order(t_stack *lst)
{
	int		min;
	t_stack	*current;

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

int	ft_check_rev_order(t_stack *lst)
{
	int		max;
	t_stack	*current;

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
