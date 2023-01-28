/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:24 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/28 19:16:15 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exec_cmd(t_stack **a, t_stack **b, t_stack **cmd, t_stack *cmd_sim)
{
	while (cmd_sim)
	{
		if (cmd_sim->nb == PB)
			ft_pb(a, b, cmd);
		if (cmd_sim->nb == RA)
			ft_ra(a, cmd);
		if (cmd_sim->nb == RB)
			ft_rb(b, cmd);
		if (cmd_sim->nb == RRA)
			ft_rra(a, cmd);
		if (cmd_sim->nb == RRB)
			ft_rrb(b, cmd);
		if (cmd_sim->nb == RR)
		{
			ft_ra(a, cmd);
			ft_rb(b, cmd);
		}
		if (cmd_sim->nb == RRR)
		{
			ft_rra(a, cmd);
			ft_rrb(b, cmd);
		}
		cmd_sim = cmd_sim->next;
	}
}

void	ft_free_all(t_stack **a, t_stack **b, t_stack **sorted, t_stack **cmd)
{
	ft_lstclear(cmd);
	ft_lstclear(a);
	ft_lstclear(b);
	ft_lstclear(sorted);
}

void	ft_print_instr(t_stack **cmd)
{
	if ((*cmd)->nb == PA)
		printf("pa\n");
	if ((*cmd)->nb == RR)
		printf("rr\n");
	if ((*cmd)->nb == RRR)
		printf("rrr\n");
	if ((*cmd)->nb == PB)
		printf("pb\n");
	if ((*cmd)->nb == SA)
		printf("sa\n");
	if ((*cmd)->nb == SB)
		printf("sb\n");
	if ((*cmd)->nb == RA)
		printf("ra\n");
	if ((*cmd)->nb == RB)
		printf("rb\n");
	if ((*cmd)->nb == RRA)
		printf("rra\n");
	if ((*cmd)->nb == RRB)
		printf("rrb\n");
	*cmd = (*cmd)->next;
}
