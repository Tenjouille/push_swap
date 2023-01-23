/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:29:16 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/23 18:35:32 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_up(t_stack **a, t_stack **b, t_stack *sorted, t_stack **cmd)
{
	if ((*a)->nb == ft_min(*a) || (ft_lstsize(sorted) == 6 && (*a)->nb <= ft_median(sorted)))
		ft_pb(a, b, cmd);
	else
	{
		if (ft_next_move(*a) > 0)
		{
			while ((*a)->nb != ft_min(*a))
			{
				if (ft_lstsize(sorted) == 6 && (*a)->nb <= ft_median(sorted))
					break ;
				ft_ra(a, cmd);
			}
			ft_pb(a, b, cmd);
		}
		else
		{
			while ((*a)->nb != ft_min(*a))
			{
				if (ft_lstsize(sorted) == 6 && (*a)->nb <= ft_median(sorted))
					break ;
				ft_rra(a, cmd);
			}
			ft_pb(a, b, cmd);
		}
	}
	if (ft_lstsize(*a) > 3)
		ft_push_up(a, b, sorted, cmd);
}

t_stack	*ft_improve(t_stack **cmd)
{
	t_stack	*cmp;
	t_stack	*current;
	t_stack	*prev;

	cmp = *cmd;
	while (cmp)
	{
		prev = cmp;
		current = cmp->next;
		while (current && (current->nb != PA && current->nb != PB))
		{
			if (cmp->nb == current->nb + 1 || cmp->nb == current->nb - 1)
			{
				cmp->nb = cmp->nb + current->nb;
				prev->next = ft_delone(current);
				break ;
			}
			current = current->next;
			prev = prev->next;
		}
		cmp = cmp->next;
	}
	return (*cmd);
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