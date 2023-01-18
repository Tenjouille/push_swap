/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:15:52 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/18 18:11:13 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_lstclear(t_list **stack)
// {
// 	t_list	*current;
// 	t_list	*tmp;

// 	current = *stack;
// 	while (current != NULL)
// 	{
// 		tmp = current->next;
// 		free (current);
// 		current = tmp;
// 	}
// }
// *stack = NULL;

int	ft_lst_cmp(t_list *lst_a, t_list *lst_b)
{
	while (lst_a->next && lst_a->nb == lst_b->nb)
	{
		lst_a = lst_a->next;
		lst_b = lst_b->next;
	}
	return (lst_a->nb - lst_b->nb);
}

void	sort_list(t_list *lst)
{
	t_list	*cmp;

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

t_list	*list_inputs(int ac, char **av)
{
	t_list	*stack;
	t_list	*new;
	int		i;

	stack = ft_lstnew(ft_atol(av[1]));
	i = 2;
	new = stack->next;
	ft_lstadd_back(&stack, new);
	while (i < ac)
	{
		new = ft_lstnew(ft_atol(av[i]));
		ft_lstadd_back(&stack, new);
		new = new->next;
		i++;
	}
	return (stack);
}
