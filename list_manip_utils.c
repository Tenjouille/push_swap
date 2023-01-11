/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:44:44 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/11 17:31:45 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstnew(int nb)
{
	t_list	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		last = ft_lstlast(lst);
		last->next = new;
	}
	else
		lst = new;
}

void	ft_lstadd_front(t_list *lst, t_list *new)
{
	t_list	*tmp;

	tmp = lst;
	lst = new;
	new->next = tmp;
}
