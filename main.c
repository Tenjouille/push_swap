/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:56:32 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/28 19:32:08 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-')
	{
		i++;
		sign = -sign;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' )
			return (2147483648);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	t_stack	*sorted_stack;
	t_stack	*cmd;
	t_stack	*cur;

	if (!ft_parsing(ac, av) || ac == 1)
		return (0);
	cmd = NULL;
	b_stack = NULL;
	a_stack = list_inputs(ac, av);
	sorted_stack = list_inputs(ac, av);
	sort_list(sorted_stack);
	if (ft_check_order(a_stack))
		return (0);
	if (ft_lstsize(a_stack) <= 6)
		ft_lil_algo(&a_stack, &b_stack, sorted_stack, &cmd);
	else
		ft_big_algo(&a_stack, &b_stack, &cmd);
	ft_improve(&cmd);
	cur = cmd;
	while (cur)
		ft_print_instr(&cur);
	ft_free_all(&a_stack, &b_stack, &sorted_stack, &cmd);
	return (0);
}
	// while(a_stack != NULL)
	// {
	// 	printf("Liste a : %d\n", a_stack->nb);
	// 	a_stack = a_stack->next;
	// }
	// while(a_stack != NULL)
	// {
	// 	printf("Liste a : %d\n", a_stack->nb);
	// 	a_stack = a_stack->next;
	// }
	// printf("\n\n\n");
	// while(b_stack != NULL)
	// {
	// 	printf("Liste b :%d\n", b_stack->nb);
	// 	b_stack = b_stack->next;
	// }
	// ft_free_all(&a_stack, &b_stack, &sorted_stack, &cmd);
	// printf("\n\n\n");
	// printf("\n\n\n");
	// while(sorted_stack != NULL)
	// {
	// 	printf("Sorted list : %d\n", sorted_stack->nb);
	// 	sorted_stack = sorted_stack->next;
	// }
	// printf("\n\n\n");