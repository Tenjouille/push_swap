/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:13:30 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/25 09:14:12 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **lst, t_stack **instruction)
{
	t_stack	*new;

	new = ft_lstnew(RA);
	ft_lstadd_back(instruction, new);
	ft_rotate(lst);
}

void	ft_rb(t_stack **lst, t_stack **instruction)
{
	t_stack	*new;

	new = ft_lstnew(RB);
	ft_lstadd_back(instruction, new);
	ft_rotate(lst);
}

void	ft_rra(t_stack **lst, t_stack **instruction)
{
	t_stack	*new;

	new = ft_lstnew(RRA);
	ft_lstadd_back(instruction, new);
	ft_reverse_rotate(lst);
}

void	ft_rrb(t_stack **lst, t_stack **instruction)
{
	t_stack	*new;

	new = ft_lstnew(RRB);
	ft_lstadd_back(instruction, new);
	ft_reverse_rotate(lst);
}
