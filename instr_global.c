/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_global.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 09:08:03 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/04 16:24:41 by tbourdea         ###   ########.fr       */
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

void	ft_rotate(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst || !lst || !(*lst)->next)
		return ;
	tmp = (*lst)->next;
	ft_lstadd_back(&tmp, *lst);
	(*lst)->next = NULL;
	*lst = tmp;
}

void	ft_reverse_rotate(t_stack **lst)
{
	t_stack	*new_start;
	t_stack	*new_end;

	if (!*lst || !lst || !(*lst)->next)
		return ;
	new_end = *lst;
	new_start = ft_lstlast(*lst);
	while (new_end->next != new_start)
		new_end = new_end->next;
	ft_lstadd_front(lst, new_start);
	new_end->next = NULL;
	*lst = new_start;
}
