/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_push_n_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:15:35 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/25 09:16:22 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int *a, int *b, t_stack **instruction)
{
	t_stack	*new;

	new = ft_lstnew(SA);
	ft_lstadd_back(instruction, new);
	ft_swap(a, b);
}

void	ft_sb(int *a, int *b, t_stack **instruction)
{
	t_stack	*new;

	new = ft_lstnew(SB);
	ft_lstadd_back(instruction, new);
	ft_swap(a, b);
}

void	ft_pa(t_stack **from_stack, t_stack **to_stack, t_stack **instruction)
{
	t_stack	*new;

	new = ft_lstnew(PA);
	ft_lstadd_back(instruction, new);
	ft_push(from_stack, to_stack);
}

void	ft_pb(t_stack **from_stack, t_stack **to_stack, t_stack **instruction)
{
	t_stack	*new;

	new = ft_lstnew(PB);
	ft_lstadd_back(instruction, new);
	ft_push(from_stack, to_stack);
}
