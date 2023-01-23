/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:56:32 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/23 18:19:25 by tbourdea         ###   ########.fr       */
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

int	ft_parsing(int ac, char **av)
{
	int		i;
	int		j;

	j = 0;
	i = ac;
	while (--i > 0)
		if (!ft_micro_parsing(av[++j]))
			return (write(2, "Error\n", 6), 0);
	i = ac;
	while (--i > 0)
	{
		j = i;
		while (--j > 0)
			if (ft_atol(av[j]) == ft_atol(av[i]))
				return (write(2, "Error\n", 6), 0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_stack	*b_stack;
	t_stack	*sorted_stack;
	t_stack	*cmd;

	if (!ft_parsing(ac, av) || ac == 1)
		return (0);
	// write(1, "Parameters : OK\n", 16);
	cmd = NULL;
	b_stack = NULL;
	a_stack = list_inputs(ac, av);
	sorted_stack = list_inputs(ac, av);
	sort_list(sorted_stack);
	if (!ft_lst_cmp(a_stack, sorted_stack))
		return (0);
	ft_lil_algo(&a_stack, &b_stack, sorted_stack, &cmd);
	
	// while (ft_lst_cmp(a_stack, sorted_stack))
	// {
	// 	ft_algorythm(&a_stack, &b_stack, sorted_stack, &cmd);
	// 	while (a_stack != NULL/* && ft_lstlast(sorted_stack)->nb != a_stack->nb*/)
	// 		ft_pa(&a_stack, &b_stack, &cmd);		
	// 	ft_empty_b(&b_stack, &a_stack, sorted_stack, &cmd);
	// }
	// ft_algo_three(&a_stack, &b_stack, sorted_stack);	

	// printf("\n\n\n");
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
	// printf("\n\n\n");
	// while(sorted_stack != NULL)
	// {
	// 	printf("Sorted list : %d\n", sorted_stack->nb);
	// 	sorted_stack = sorted_stack->next;
	// }
	// printf("\n\n\n");
	// cmd = ft_improve(&cmd);
	while(cmd != NULL)
	{
		if (cmd->nb == PA)
			printf("pa\n");
		if (cmd->nb == SS)
			printf("ss\n");
		if (cmd->nb == RR)
			printf("rr\n");
		if (cmd->nb == RRR)
			printf("rrr\n");
		if (cmd->nb == PB)
			printf("pb\n");
		if (cmd->nb == SA)
			printf("sa\n");
		if (cmd->nb == SB)
			printf("sb\n");
		if (cmd->nb == RA)
			printf("ra\n");
		if (cmd->nb == RB)
			printf("rb\n");
		if (cmd->nb == RRA)
			printf("rra\n");
		if (cmd->nb == RRB)
			printf("rrb\n");
		cmd = cmd->next;
	}
	return (0);
}
