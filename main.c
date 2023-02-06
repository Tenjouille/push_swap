/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:56:32 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/06 19:40:08 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	t_stack	*cmd;
	t_stack	*cur;

	if (!ft_parsing(ac, av) || ac == 1)
		return (0);
	cmd = NULL;
	b_stack = NULL;
	a_stack = list_inputs(ac, av);
	if (!a_stack)
		return (ft_free_all(&a_stack, &b_stack, &cmd), 0);
	if (ft_check_order(a_stack))
		return (ft_free_all(&a_stack, &b_stack, &cmd), 0);
	if (ft_lstsize(a_stack) <= 6)
		ft_lil_algo(&a_stack, &b_stack, &cmd);
	else
		ft_big_algo(&a_stack, &b_stack, &cmd);
	ft_improve(&cmd);
	cur = cmd;
	while (cur)
		ft_print_instr(&cur);
	return (ft_free_all(&a_stack, &b_stack, &cmd), 0);
}

	// while((*from_stack) != NULL)
	// {
	// 	printf("Liste a : %d\n", (*from_stack)->nb);
	// 	(*from_stack) = (*from_stack)->next;
	// }
	// // while((*a) != NULL)
	// // {
	// // 	printf("Liste a : %d\n", (*a)->nb);
	// // 	(*a) = (*a)->next;
	// // }
	// printf("\n\n\n");
	// while((*to_stack) != NULL)
	// {
	// 	printf("Liste b :%d\n", (*to_stack)->nb);
	// 	(*to_stack) = (*to_stack)->next;
	// }
	// printf("\n\n\n");
	// printf("\n\n\n");
	// while((*cmd) != NULL)
	// {
	// 	printf("Cmd list : %d\n", (*cmd)->nb);
	// 	(*cmd) = (*cmd)->next;
	// }
	// printf("\n\n\n");