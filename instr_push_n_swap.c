/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push_n_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:15:35 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/06 19:27:13 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a, t_stack **b, t_stack **cmd)
{
	t_stack	*new;

	new = ft_lstnew(SA);
	if (!new)
	{
		ft_free_all(a, b, cmd);
		exit (0);
	}
	ft_lstadd_back(cmd, new);
	ft_swap(&(*a)->nb, &(*a)->next->nb);
}

void	ft_sb(t_stack **a, t_stack **b, t_stack **cmd)
{
	t_stack	*new;

	new = ft_lstnew(SB);
	if (!new)
	{
		ft_free_all(a, b, cmd);
		exit (0);
	}
	ft_lstadd_back(cmd, new);
	ft_swap(&(*b)->nb, &(*b)->next->nb);
}

void	ft_pa(t_stack **from_stack, t_stack **to_stack, t_stack **cmd)
{
	t_stack	*new;

	new = ft_lstnew(PA);
	if (!new)
	{
		ft_free_all(from_stack, to_stack, cmd);
		exit (0);
	}
	ft_lstadd_back(cmd, new);
	ft_push(from_stack, to_stack);
}

void	ft_pb(t_stack **from_stack, t_stack **to_stack, t_stack **cmd)
{
	t_stack	*new;

	new = ft_lstnew(PB);
	if (!new)
	{
		ft_free_all(from_stack, to_stack, cmd);
		exit (0);
	}
	ft_lstadd_back(cmd, new);
	ft_push(from_stack, to_stack);
}
