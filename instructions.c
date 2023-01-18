/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:15:35 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/17 16:37:01 by tbourdea         ###   ########.fr       */
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

void	ft_sa(int *a, int *b)
{
	ft_swap(a, b);
	write(1, "sa\n", 3);
}

void	ft_sb(int *a, int *b)
{
	ft_swap(a, b);
	write(1, "sb\n", 3);
}

void	ft_push(t_list **from_list, t_list **to_list)
{
	t_list	*tmp;

	if (!*from_list || !from_list)
		return ;
	tmp = (*from_list)->next;
	(*from_list)->next = *to_list;
	*to_list = *from_list;
	*from_list = tmp;
}

void	ft_pa(t_list **from_list, t_list **to_list)
{
	ft_push(from_list, to_list);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **from_list, t_list **to_list)
{
	ft_push(from_list, to_list);
	write(1, "pb\n", 3);
}

void	ft_rotate(t_list **lst)
{
	t_list	*tmp;
	if (!*lst || !lst)
		return ;
	tmp = (*lst)->next;
	ft_lstadd_back(&tmp, *lst);
	(*lst)->next = NULL;
	*lst = tmp;
}

void	ft_ra(t_list **lst)
{
	ft_rotate(lst);
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **lst)
{
	ft_rotate(lst);
	write(1, "rb\n", 3);
}

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*new_start;
	t_list	*new_end;

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

void	ft_rra(t_list **lst)
{
	ft_reverse_rotate(lst);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **lst)
{
	ft_reverse_rotate(lst);
	write(1, "rrb\n", 4);
}