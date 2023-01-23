/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:15:35 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/23 18:03:05 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

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

void	ft_push(t_stack **from_stack, t_stack **to_stack)
{
	t_stack	*tmp;

	if (!*from_stack || !from_stack)
		return ;
	tmp = (*from_stack)->next;
	(*from_stack)->next = *to_stack;
	*to_stack = *from_stack;
	*from_stack = tmp;
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

void	ft_rotate(t_stack **lst)
{
	t_stack	*tmp;
	
	if (!*lst || !lst)
		return ;
	tmp = (*lst)->next;
	ft_lstadd_back(&tmp, *lst);
	(*lst)->next = NULL;
	*lst = tmp;
}

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

void	ft_reverse_rotate(t_stack **lst)
{
	t_stack	*new_start;
	t_stack	*new_end;

	if (!*lst || !lst)
		return ;
	new_end = *lst;
	new_start = ft_lstlast(*lst);
	while (new_end->next != new_start)
		new_end = new_end->next;
	ft_lstadd_front(lst, new_start);
	new_end->next = NULL;
	*lst = new_start;
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