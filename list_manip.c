/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:15:52 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/07 15:48:11 by tbourdea         ###   ########.fr       */
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

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
}

t_stack	*list_inputs(int ac, char **av)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	stack = ft_lstnew(ft_atol(av[1]));
	if (!stack)
		return (NULL);
	i = 1;
	new = NULL;
	while (++i < ac)
	{
		new = ft_lstnew(ft_atol(av[i]));
		if (!new)
			return (free(new), NULL);
		ft_lstadd_back(&stack, new);
		new = new->next;
	}
	new = NULL;
	return (stack);
}

void	ft_free_all(t_stack **a, t_stack **b, t_stack **cmd)
{
	ft_lstclear(cmd);
	ft_lstclear(a);
	ft_lstclear(b);
}
