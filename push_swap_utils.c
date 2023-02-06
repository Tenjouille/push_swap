/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:06:13 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/06 16:46:16 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_best_rot(t_stack *cur, t_stack **a, t_stack **b, t_stack **cmd)
{
	int	r_move;
	int	rr_move;
	int	i;

	i = -1;
	r_move = ft_lstsize(*a);
	rr_move = 0;
	while (cur)
	{
		cur = cur->next;
		r_move--;
		rr_move++;
	}
	cur = *a;
	while (++i < r_move)
		cur = cur->next;
	if (rr_move < r_move)
		while (cur != *a)
			ft_rra(a, b, cmd);
	else
		while (cur != *a)
			ft_ra(a, b, cmd);
}

int	ft_next_move(t_stack *lst)
{
	int		i;
	int		j;
	t_stack	*cur;

	i = 0;
	j = ft_lstsize(lst);
	cur = lst;
	while (cur->nb != ft_min(lst))
	{
		cur = cur->next;
		i++;
	}
	cur = lst;
	while (cur != ft_lstlast(lst) && cur->nb != ft_min(lst))
	{
		cur = cur->next;
		j--;
	}
	if (i > j)
		return (-1);
	return (1);
}
