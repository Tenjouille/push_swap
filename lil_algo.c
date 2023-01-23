/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lil_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:50:53 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/23 18:19:37 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lil_algo(t_stack **a, t_stack **b, t_stack *sorted, t_stack **cmd)
{
	if (ft_lstsize(*a) <= 6)
	{
		if (ft_lstsize(*a) == 2)
			ft_sa(&(*a)->nb, &(*a)->next->nb, cmd);
		else
		{
			if (ft_lstsize(*a) > 3)
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