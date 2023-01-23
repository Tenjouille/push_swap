/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:06:13 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/23 16:46:16 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_next_move(t_stack *lst)
{
	int		i;
	int		j;
	t_stack	*cur;

	i = 0;
	j = ft_lstsize(lst);
	cur = lst;
	while (cur->nb != ft_min(lst))
	{
		cur = cur->next;
		i++;
	}
	cur = lst;
	// while (cur->nb != ft_median(lst))
	// 	cur = cur->next;
	while (cur != ft_lstlast(lst) && cur->nb != ft_min(lst))
	{
		cur = cur->next;
		j--;
	}
	if (i > j)
		return (-1);
	return (1);
}