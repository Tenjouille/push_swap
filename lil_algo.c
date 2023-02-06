/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:53 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/06 19:38:10 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_median(t_stack *lst)
{
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(lst);
	if (size % 2 == 0)
		size--;
	while (i < size / 2)
	{
		lst = lst->next;
		i++;
	}
	return (lst->nb);
}

void	ft_push_up(t_stack **a, t_stack **b, t_stack **cmd)
{
	if ((*a)->nb == ft_min(*a))
		ft_pb(a, b, cmd);
	else
	{
		if (ft_next_move(*a) > 0)
			while ((*a)->nb != ft_min(*a))
				ft_ra(a, b, cmd);
		else
			while ((*a)->nb != ft_min(*a))
				ft_rra(a, b, cmd);
	}
}

void	ft_algo_three(t_stack **a, t_stack **b, t_stack **cmd)
{
	if (!*a || !a)
		return ;
	if (ft_max(*a) == (*a)->nb)
		ft_ra(a, b, cmd);
	if (ft_min(*a) == (*a)->next->nb)
		ft_sa(a, b, cmd);
	if (ft_lstlast((*a))->nb == ft_min(*a))
		ft_rra(a, b, cmd);
	if (!ft_check_order(*a))
	{
		ft_rra(a, b, cmd);
		ft_sa(a, b, cmd);
	}
}

void	ft_rev_algo_three(t_stack **a, t_stack **b, t_stack **cmd)
{
	if (!*b || !b)
		return ;
	if (ft_min(*b) == (*b)->nb)
		ft_rb(a, b, cmd);
	if (ft_max(*b) == (*b)->next->nb)
		ft_sb(a, b, cmd);
	if (ft_lstlast((*b))->nb == ft_max(*b))
		ft_rrb(a, b, cmd);
	if (!ft_check_rev_order(*b))
	{
		ft_rrb(a, b, cmd);
		ft_sb(a, b, cmd);
	}
}

void	ft_lil_algo(t_stack **a, t_stack **b, t_stack **cmd)
{
	if (ft_lstsize(*a) == 2)
		ft_sa(a, b, cmd);
	else
	{
		while (ft_lstsize(*a) > 3)
			ft_push_up(a, b, cmd);
		if (ft_lstsize(*b) == 2 && !ft_check_rev_order(*b))
			ft_sa(a, b, cmd);
		ft_algo_three(a, b, cmd);
		if (ft_lstsize(*b) == 3 && !ft_check_rev_order(*b))
			ft_rev_algo_three(a, b, cmd);
		while (*b)
			ft_pa(b, a, cmd);
	}
}
