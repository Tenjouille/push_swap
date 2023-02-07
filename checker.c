/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:35:54 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/07 18:03:25 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include "get_next_line.h"

void	ft_fill_cmd(char *str, t_stack **cmd)
{
	if (!ft_strcmp(str, "pa\n"))
		ft_new_cmd(PA, cmd);
	if (!ft_strcmp(str, "pb\n"))
		ft_new_cmd(PB, cmd);
	if (!ft_strcmp(str, "sa\n"))
		ft_new_cmd(SA, cmd);
	if (!ft_strcmp(str, "sb\n"))
		ft_new_cmd(SB, cmd);
	if (!ft_strcmp(str, "ss\n"))
		ft_new_cmd(SS, cmd);
	if (!ft_strcmp(str, "ra\n"))
		ft_new_cmd(RA, cmd);
	if (!ft_strcmp(str, "rb\n"))
		ft_new_cmd(RB, cmd);
	if (!ft_strcmp(str, "rr\n"))
		ft_new_cmd(RR, cmd);
	if (!ft_strcmp(str, "rra\n"))
		ft_new_cmd(RRA, cmd);
	if (!ft_strcmp(str, "rrb\n"))
		ft_new_cmd(RRB, cmd);
	if (!ft_strcmp(str, "rrr\n"))
		ft_new_cmd(RRR, cmd);
}

void	ft_execute_rotations_cmd(t_stack **a, t_stack **b, t_stack *cmd)
{
	if (cmd->nb == RA)
		ft_rotate(a);
	if (cmd->nb == RB)
		ft_rotate(b);
	if (cmd->nb == RR)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	if (cmd->nb == RRA)
		ft_reverse_rotate(a);
	if (cmd->nb == RRB)
		ft_reverse_rotate(b);
	if (cmd->nb == RRR)
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
	}
}

void	ft_execute_cmd(t_stack **a, t_stack **b, t_stack *cmd)
{
	
		if (cmd->nb == SA)
			if (*a && (*a)->next)
				ft_swap(&(*a)->nb, &(*a)->next->nb);
		if (cmd->nb == SB)
			if (*b && (*b)->next)
				ft_swap(&(*b)->nb, &(*b)->next->nb);
		if (cmd->nb == SS)
		{
			if (*a && (*a)->next && *b && (*b)->next)
			{
				ft_swap(&(*a)->nb, &(*a)->next->nb);
				ft_swap(&(*b)->nb, &(*b)->next->nb);
			}
		}
	if (cmd->nb == PA)
		ft_push(b, a);
	if (cmd->nb == PB)
		ft_push(a, b);
	ft_execute_rotations_cmd(a, b, cmd);
}

void	ft_scan_standard_inputs(t_stack **cmd)
{
	char	*buff;
	
	buff = get_next_line(0, 1);
	while (buff)
	{
		if (!ft_cmd_parsing(buff))
			ft_quit_prog(buff, cmd);
		ft_fill_cmd(buff, cmd);
		free (buff);
		buff = get_next_line(0, 1);
	}
	free (buff);
}

int	main(int ac, char **av)
{
	t_stack	*cmd;
	t_stack	*a;
	t_stack	*b;
	t_stack	*new;

	if (!ft_parsing(ac, av) || ac == 1)
		return (0);
	cmd = NULL;
	ft_scan_standard_inputs(&cmd);
	new = cmd;
	a = list_inputs(ac, av);
	b = NULL;
	while (new)
	{
		ft_execute_cmd(&a, &b, new);
		new = new->next;
	}
	if (ft_check_order(a) && b == NULL)
		return (ft_free_all(&a, &b, &cmd), write(1, "OK\n", 3), 0);
	return (ft_free_all(&a, &b, &cmd), write(1, "KO\n", 3), 0);
}
