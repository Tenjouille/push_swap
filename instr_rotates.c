/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:13:30 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/06 19:26:56 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a, t_stack **b, t_stack **cmd)
{
	t_stack	*new;

	new = ft_lstnew(RA);
	if (!new)
	{
		ft_free_all(a, b, cmd);
		exit (0);
	}
	ft_lstadd_back(cmd, new);
	ft_rotate(a);
}

void	ft_rb(t_stack **a, t_stack **b, t_stack **cmd)
{
	t_stack	*new;

	new = ft_lstnew(RB);
	if (!new)
	{
		ft_free_all(a, b, cmd);
		exit (0);
	}
	ft_lstadd_back(cmd, new);
	ft_rotate(b);
}

void	ft_rra(t_stack **a, t_stack **b, t_stack **cmd)
{
	t_stack	*new;

	new = ft_lstnew(RRA);
	if (!new)
	{
		ft_free_all(a, b, cmd);
		exit (0);
	}
	ft_lstadd_back(cmd, new);
	ft_reverse_rotate(a);
}

void	ft_rrb(t_stack **a, t_stack **b, t_stack **cmd)
{
	t_stack	*new;

	new = ft_lstnew(RRB);
	if (!new)
	{
		ft_free_all(a, b, cmd);
		exit (0);
	}
	ft_lstadd_back(cmd, new);
	ft_reverse_rotate(b);
}
