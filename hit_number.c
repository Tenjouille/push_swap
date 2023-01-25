/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:31:26 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/25 09:00:12 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_hit_nb(t_stack *current, t_stack *stack)
{
	int		total_move;
	int		r_move;
	int		rr_move;

	total_move = 0;
	rr_move = 0;
	r_move = ft_lstsize(stack);
	while (current && current != stack)
	{
		current = current->next;
		rr_move++;
		r_move--;
	}
	if (rr_move < r_move)
		total_move += rr_move;
	else
		total_move += r_move;
	return (total_move);
}
