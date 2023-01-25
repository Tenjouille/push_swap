/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:15:52 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/25 08:54:07 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lst_cmp(t_stack *lst_a, t_stack *lst_b)
{
	while (lst_a->next && lst_a->nb == lst_b->nb)
	{
		lst_a = lst_a->next;
		lst_b = lst_b->next;
	}
	return (lst_a->nb - lst_b->nb);
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
