/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:40 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/11 20:07:22 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_median(t_list *lst)
{
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(lst);
	if (size % 2 == 0)
		size--;
	while (i < size / 2)
	{
		lst = lst->next;
		i++;
	}
	return (lst->nb);
}

int	ft_scan(t_list *lst, int median)
{
	while (lst)
	{
		if (lst->nb <= median)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_algorythm(t_list **a_stack, t_list **b_stack, t_list **sorted_stack)
{
	int	median;
	int	count;

	count = 0;
	median = ft_median(*sorted_stack);
	printf ("Mediane = %d\n", median);
	while ((*a_stack)->nb <= median)
	{
		ft_push(a_stack, b_stack);
		count++;
		printf("push number %d : b_start = %d\n", count, (*b_stack)->nb);
	}
	if ((*a_stack)->next->nb <= median)
	{
		ft_swap(&(*a_stack)->nb, &(*a_stack)->next->nb);
		printf("swap number %d : %d passe en first\n", count, (*a_stack)->nb);	
	}
	else if (ft_scan(*a_stack, median))
	{
		while((*a_stack)->nb > median)
			ft_reverse_rotate(a_stack);
	}
	if (count != 0)
		ft_algorythm(&*a_stack, &*b_stack, sorted_stack);
}