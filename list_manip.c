/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:15:52 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/27 18:21:45 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstdelone(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst->next;
	free (lst);
	return (tmp);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
}

void	sort_list(t_stack *lst)
{
	t_stack	*cmp;

	while (lst->next)
	{
		cmp = lst->next;
		while (cmp)
		{
			if (lst->nb > cmp->nb)
				ft_swap(&lst->nb, &cmp->nb);
			cmp = cmp->next;
		}
		lst = lst->next;
	}
}

t_stack	*list_inputs(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	stack = ft_lstnew(ft_atol(av[1]));
	i = 2;
	new = NULL;
	while (i < ac)
	{
		new = ft_lstnew(ft_atol(av[i]));
		ft_lstadd_back(&stack, new);
		new = new->next;
		i++;
	}
	new = NULL;
	return (stack);
}
