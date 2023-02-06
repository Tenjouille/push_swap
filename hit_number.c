/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:31:26 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/03 16:53:36 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_first_in_b(int ref, t_stack *b)
{
	int		prev;
	t_stack	*cur;

	prev = -2147483648;
	cur = b;
	while (cur)
	{
		if (cur->nb < ref && cur->nb > prev)
			prev = cur->nb;
		cur = cur->next;
	}
	cur = b;
	if (ref < ft_min(b) || ref > ft_max(b))
	{
		while (ft_max(b) != cur->nb)
			cur = cur->next;
		return (cur);
	}
	while (cur->nb != prev)
		cur = cur->next;
	return (cur);
}

t_stack	*find_best_move(t_stack *a, t_stack *b, t_stack **cmd_sim)
{
	int		min_cmd;
	t_stack	*cur;

	cur = a;
	min_cmd = 5500;
	while (cur)
	{
		ft_a_move_nb(cur, a, cmd_sim);
		ft_b_move_nb(ft_first_in_b(cur->nb, b), b, cmd_sim);
		if (min_cmd > ft_lstsize(*cmd_sim))
			min_cmd = ft_lstsize(*cmd_sim);
		ft_lstclear(cmd_sim);
		cur = cur->next;
	}
	cur = a;
	ft_a_move_nb(cur, a, cmd_sim);
	ft_b_move_nb(ft_first_in_b(cur->nb, b), b, cmd_sim);
	while (min_cmd != ft_lstsize(*cmd_sim))
	{
		ft_lstclear(cmd_sim);
		cur = cur->next;
		ft_a_move_nb(cur, a, cmd_sim);
		ft_b_move_nb(ft_first_in_b(cur->nb, b), b, cmd_sim);
	}
	return (*cmd_sim);
}

void	ft_new_cmd(int cmd, t_stack **stack)
{
	t_stack	*new;

	new = ft_lstnew(cmd);
	ft_lstadd_back(stack, new);
}

void	ft_a_move_nb(t_stack *current, t_stack *a, t_stack **cmd_sim)
{
	int		r_move;
	int		rr_move;

	rr_move = 0;
	r_move = ft_lstsize(a);
	while (current && current != a)
	{
		current = current->next;
		rr_move++;
		r_move--;
	}
	if (rr_move < r_move)
		while (--rr_move >= 0)
			ft_new_cmd(RRA, cmd_sim);
	else
		while (--r_move >= 0)
			ft_new_cmd(RA, cmd_sim);
}

void	ft_b_move_nb(t_stack *current, t_stack *b, t_stack **cmd_sim)
{
	int		r_move;
	int		rr_move;

	rr_move = 0;
	r_move = ft_lstsize(b);
	while (current && current != b)
	{
		current = current->next;
		rr_move++;
		r_move--;
	}
	if (rr_move < r_move)
		while (--rr_move >= 0)
			ft_new_cmd(RRB, cmd_sim);
	else
		while (--r_move >= 0)
			ft_new_cmd(RB, cmd_sim);
	ft_new_cmd(PB, cmd_sim);
	ft_improve(cmd_sim);
}
