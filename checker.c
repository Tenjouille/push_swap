/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:35:54 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/04 16:22:44 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s2[i] - s1[i]);
}

int	ft_cmd_parsing(char *s)
{
	if (!ft_strcmp(s, "sa\n") || !ft_strcmp(s, "sb\n") || !ft_strcmp(s, "ss\n"))
		return (1);
	if (!ft_strcmp(s, "ra\n") || !ft_strcmp(s, "rb\n") || !ft_strcmp(s, "rr\n"))
		return (1);
	if (!ft_strcmp(s, "rra\n") || !ft_strcmp(s, "rrb\n") || !ft_strcmp(s, "rrr\n"))
		return (1);
	if (!ft_strcmp(s, "pa\n") || !ft_strcmp(s, "pb\n"))
		return (1);
	return (0);
}

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

void	ft_execute_cmd(t_stack **a, t_stack **b, t_stack *cmd)
{
	if (cmd->nb == SA)
		ft_swap(&(*a)->nb, &(*a)->next->nb);
	if (cmd->nb == SB)
		ft_swap(&(*b)->nb, &(*b)->next->nb);
	if (cmd->nb == SS)
	{
		ft_swap(&(*a)->nb, &(*a)->next->nb);
		ft_swap(&(*b)->nb, &(*b)->next->nb);
	}
	if (cmd->nb == PA)
		ft_push(b, a);
	if (cmd->nb == PB)
		ft_push(a, b);
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

int	main(int ac, char **av)
{
	t_stack	*cmd;
	t_stack	*a;
	t_stack	*b;
	t_stack	*new;
	char	*buff;

	if (!ft_parsing(ac, av) || ac == 1)
		return (0);
	cmd = NULL;
	buff = get_next_line(0);
	while (buff)
	{
		if (!ft_cmd_parsing(buff))
		{
			free (buff);
			ft_lstclear(&cmd);
			return (write(2, "Error\n", 6), 0);
		}
		ft_fill_cmd(buff, &cmd);
		free (buff);
		buff = get_next_line(0);
	}
	free (buff);
	new = cmd;
	a = list_inputs(ac, av);
	b = NULL;
	while (new)
	{
		ft_execute_cmd(&a, &b, new);
		new = new->next;
	}
	ft_lstclear(&cmd);
	if (ft_check_order(a) && b == NULL)
	{
		ft_lstclear(&a);
		ft_lstclear(&b);
		return (write(1, "OK\n", 3));
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (write(1, "KO\n", 3), 0);
}
