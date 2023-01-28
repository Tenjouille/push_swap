/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:40 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/28 19:55:17 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_a(t_stack **a, t_stack **cmd)
{
	t_stack	*cur;
	int		i;

	i = 1;
	cur = *a;
	while (cur->nb != ft_min(*a))
	{
		cur = cur->next;
		i++;
	}
	if (cur->nb == ft_median(*a) || i <= ft_lstsize(*a) / 2)
		while ((*a)->nb != ft_min(*a))
			ft_ra(a, cmd);
	else
		while ((*a)->nb != ft_min(*a))
			ft_rra(a, cmd);
}

void	ft_empty_b(t_stack **a, t_stack **b, t_stack **cmd)
{
	t_stack	*cur;

	cur = *a;
	if (ft_scan((*b)->nb, *a) == (*a)->nb
		|| ((*b)->nb > ft_max(*a) && (*a)->nb == ft_min(*a))
		|| ((*b)->nb < ft_min(*a) && (*a)->nb == ft_min(*a)))
		ft_pa(b, a, cmd);
	else if ((*b)->nb > ft_max(*a) || (*b)->nb < ft_min(*a))
	{
		while (cur->nb != ft_min(*a))
			cur = cur->next;
		ft_best_rotation(cur, a, cmd);
	}
	else
	{
		while (cur->nb != ft_scan((*b)->nb, *a))
			cur = cur->next;
		ft_best_rotation(cur, a, cmd);
	}
	if (*b)
		ft_empty_b(a, b, cmd);
}

int	ft_scan(int ref, t_stack *lst)
{
	int	the_one;

	if (ref < ft_min(lst) || ref > ft_max(lst))
		return (ref);
	while (lst->nb < ref)
		lst = lst->next;
	the_one = lst->nb;
	while (lst)
	{
		if (lst->nb < the_one && lst->nb > ref)
			the_one = lst->nb;
		lst = lst->next;
	}
	return (the_one);
}

void	ft_algorithm(t_stack **a, t_stack **b, t_stack **cmd)
{
	t_stack	*cmd_sim;

	cmd_sim = NULL;
	cmd_sim = find_best_move(*a, *b, &cmd_sim);
	ft_exec_cmd(a, b, cmd, cmd_sim);
	ft_lstclear(&cmd_sim);
	if (ft_lstsize(*a) > 3)
		ft_algorithm(a, b, cmd);
}

void	ft_big_algo(t_stack **a, t_stack **b, t_stack **cmd)
{
	ft_pb(a, b, cmd);
	ft_pb(a, b, cmd);
	ft_algorithm(a, b, cmd);
	ft_algo_three(a, cmd);
	ft_empty_b(a, b, cmd);
	while (!ft_check_order(*a))
		ft_sort_a(a, cmd);
}
