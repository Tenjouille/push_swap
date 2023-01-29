/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:40 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/23 18:01:12 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ft_del_last : supprime le dernier element d'une liste (inutile pour l'instant)
void	ft_del_last(t_stack **lst)
{
	
	t_stack	*pos;
	t_stack	*prev;

	if (!*lst || !lst)
		return ;
	pos = *lst;
	prev = NULL;
	while (pos->next)
	{
		prev = pos;
		pos = pos->next;
	}
	free(pos);
	if (!prev)
		*lst = NULL;
	if (prev)
		prev->next = NULL;
}
//ft_median : definit la mediane de la liste triee
int	ft_median(t_stack *lst)
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

//ft_scan : parcours la liste pour savoir s'il reste des nombre plus petit ou egal a la mediane.
int	ft_scan(t_stack *lst, int median)
{
	while (lst)
	{
		if (lst->nb <= median)
			return (1);
		lst = lst->next;
	}
	return (0);
}

void	ft_algorythm(t_stack **a, t_stack **b, t_stack *sorted, t_stack **cmd)
{
	int	median;
	int	i;

	i = 0;
	median = ft_median(sorted);
	while ((*a)->nb <= median)
	{
		ft_pb(a, b, cmd);
		i++;
	}
	if ((*a)->next && (*a)->next->nb <= median)
		ft_sa(&(*a)->nb, &(*a)->next->nb, cmd);
	else if (ft_scan(*a, median))
		while((*a)->nb > median)
			ft_rra(a, cmd);
	if (i != 0)
		ft_algorythm(a, b, sorted, cmd);
}
//ft_min : definit le plus petit nombre de la lise placee en parametre
int	ft_min(t_stack *lst)
{
	int 	min;

	min = lst->nb;
	while (lst != NULL)
	{
		if (min > lst->nb)
			min = lst->nb;
		lst = lst->next;
	}
	return (min);
}

int	ft_max(t_stack *lst)
{
	int	max;

	max = lst->nb;
	while (lst != NULL)
	{
		if (max < lst->nb)
			max = lst->nb;
		lst = lst->next;
	}
	return (max);
}
//ft_empty_b : renvoie dans la liste a tous les maillons de la liste b dans l'ordre croissant
void	ft_empty_b(t_stack **b_stack, t_stack **a_stack, t_stack *sorted, t_stack **cmd)
{
	if (ft_check_rev_order(*b_stack))
	{
		while (*b_stack)
		{
			ft_pa(b_stack, a_stack, cmd);
			ft_rra(&sorted, cmd);
		}
	}
	else
	{
		if (!*b_stack || !b_stack)
			return ;
		while ((*b_stack)->nb != ft_lstlast(sorted)->nb)
		{
			ft_rrb(b_stack, cmd);
		}
		ft_pa (b_stack, a_stack, cmd);
		ft_reverse_rotate (&sorted);
		if (*b_stack)
			ft_empty_b(b_stack, a_stack, sorted, cmd);
	}
}

void	ft_algo_three(t_stack **stack, t_stack **cmd)
{
	if (!*stack || !stack)
		return ;
	if (ft_max(*stack) == (*stack)->nb)
		ft_ra(stack, cmd);
	if (ft_min(*stack)== (*stack)->next->nb)
		ft_sa(&(*stack)->nb, &(*stack)->next->nb, cmd);
	if (ft_lstlast((*stack))->nb == ft_min(*stack))
		ft_rra(stack, cmd);
	if (!ft_check_order(*stack))
	{
		ft_rra(stack, cmd);
		ft_sa(&(*stack)->nb, &(*stack)->next->nb, cmd);
	}
}

void	ft_rev_algo_three(t_stack **stack, t_stack **cmd)
{
	if (!*stack || !stack)
		return ;
	if (ft_min(*stack) == (*stack)->nb)
		ft_rb(stack, cmd);
	if (ft_max(*stack) == (*stack)->next->nb)
		ft_sb(&(*stack)->nb, &(*stack)->next->nb, cmd);
	if (ft_lstlast((*stack))->nb == ft_max(*stack))
		ft_rrb(stack, cmd);
	if (!ft_check_rev_order(*stack))
	{
		ft_rrb(stack, cmd);
		ft_sb(&(*stack)->nb, &(*stack)->next->nb, cmd);
	}
}