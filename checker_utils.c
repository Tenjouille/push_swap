/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:30:09 by tbourdea          #+#    #+#             */
/*   Updated: 2023/02/07 17:33:12 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s2[i] - s1[i]);
}

int	ft_cmd_parsing(char *s)
{
	if (!ft_strcmp(s, "sa\n") || !ft_strcmp(s, "sb\n") || !ft_strcmp(s, "ss\n"))
		return (1);
	if (!ft_strcmp(s, "ra\n") || !ft_strcmp(s, "rb\n") || !ft_strcmp(s, "rr\n"))
		return (1);
	if (!ft_strcmp(s, "rra\n") || !ft_strcmp(s, "rrb\n") || !ft_strcmp(s, "rrr\n"))
		return (1);
	if (!ft_strcmp(s, "pa\n") || !ft_strcmp(s, "pb\n"))
		return (1);
	return (0);
}

void	ft_quit_prog(char *buff, t_stack **cmd)
{
	free(buff);
	get_next_line(0, 0);
	ft_lstclear(cmd);
	write(2, "Error\n", 6);
	exit (0);
}
