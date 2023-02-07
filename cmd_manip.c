/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:24 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/07 15:48:18 by tbourdea         ###   ########.fr       */
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
			ft_ra(a, b, cmd);
		if (cmd_sim->nb == RB)
			ft_rb(a, b, cmd);
		if (cmd_sim->nb == RRA)
			ft_rra(a, b, cmd);
		if (cmd_sim->nb == RRB)
			ft_rrb(a, b, cmd);
		if (cmd_sim->nb == RR)
		{
			ft_ra(a, b, cmd);
			ft_rb(a, b, cmd);
		}
		if (cmd_sim->nb == RRR)
		{
			ft_rra(a, b, cmd);
			ft_rrb(a, b, cmd);
		}
		cmd_sim = cmd_sim->next;
	}
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
