/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:53 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/24 13:29:25 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_up(t_stack **a, t_stack **b, t_stack *sorted, t_stack **cmd)
{
	if ((*a)->nb == ft_min(*a)
		|| (ft_lstsize(sorted) >= 6 && (*a)->nb <= ft_median(sorted)))
		ft_pb(a, b, cmd);
	else
	{
		if (ft_next_move(*a) > 0)
		{
			while ((*a)->nb != ft_min(*a))
			{
				if (ft_lstsize(sorted) >= 6 && (*a)->nb <= ft_median(sorted))
					break ;
				ft_ra(a, cmd);
			}
		}
		else
		{
			while ((*a)->nb != ft_min(*a))
			{
				if (ft_lstsize(sorted) >= 6 && (*a)->nb <= ft_median(sorted))
					break ;
				ft_rra(a, cmd);
			}
		}
	}
}

void	ft_algo_three(t_stack **stack, t_stack **cmd)
{
	if (!*stack || !stack)
		return ;
	if (ft_max(*stack) == (*stack)->nb)
		ft_ra(stack, cmd);
	if (ft_min(*stack) == (*stack)->next->nb)
		ft_sa(&(*stack)->nb, &(*stack)->next->nb, cmd);
	if (ft_lstlast((*stack))->nb == ft_min(*stack))
		ft_rra(stack, cmd);
	if (!ft_check_order(*stack))
	{
		ft_rra(stack, cmd);
		ft_sa(&(*stack)->nb, &(*stack)->next->nb, cmd);
	}
}

void	ft_rev_algo_three(t_stack **stack, t_stack **cmd)
{
	if (!*stack || !stack)
		return ;
	if (ft_min(*stack) == (*stack)->nb)
		ft_rb(stack, cmd);
	if (ft_max(*stack) == (*stack)->next->nb)
		ft_sb(&(*stack)->nb, &(*stack)->next->nb, cmd);
	if (ft_lstlast((*stack))->nb == ft_max(*stack))
		ft_rrb(stack, cmd);
	if (!ft_check_rev_order(*stack))
	{
		ft_rrb(stack, cmd);
		ft_sb(&(*stack)->nb, &(*stack)->next->nb, cmd);
	}
}

void	ft_lil_algo(t_stack **a, t_stack **b, t_stack *sorted, t_stack **cmd)
{
	if (ft_lstsize(*a) <= 6)
	{
		if (ft_lstsize(*a) == 2)
			ft_sa(&(*a)->nb, &(*a)->next->nb, cmd);
		else
		{
			while (ft_lstsize(*a) > 3)
				ft_push_up(a, b, sorted, cmd);
			if (ft_lstsize(*b) == 2 && !ft_check_rev_order(*b))
				ft_sa(&(*b)->nb, &(*b)->next->nb, cmd);
			ft_algo_three(a, cmd);
			if (ft_lstsize(*b) == 3 && !ft_check_rev_order(*b))
				ft_rev_algo_three(b, cmd);
			while (*b)
				ft_pa(b, a, cmd);
		}
	}
}
