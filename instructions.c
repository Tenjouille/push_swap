/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:15:35 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/11 18:22:14 by tbourdea         ###   ########.fr       */
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

void	ft_push(t_list **from_list, t_list **to_list)
{
	t_list	*tmp;

	tmp = (*from_list)->next;
	(*from_list)->next = *to_list;
	*to_list = *from_list;
	*from_list = tmp;
}

void	ft_rotate(t_list **lst)
{
	t_list	*tmp;

	tmp = (*lst)->next;
	ft_lstadd_back(tmp, *lst);
	(*lst)->next = NULL;
	*lst = tmp;
}

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = *lst;
	tmp = ft_lstlast(*lst);
	while (tmp2->next != tmp)
		tmp2 = tmp2->next;
	ft_lstadd_front(*lst, tmp);
	tmp2->next = NULL;
	*lst = tmp;
}
