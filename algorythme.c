/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorythme.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:40 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/18 18:56:50 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//ft_del_last : supprime le dernier element d'une liste (inutile pour l'instant)
void	ft_del_last(t_list **lst)
{
	
	t_list	*pos;
	t_list	*prev;

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

//ft_scan : parcours la liste pour savoir s'il reste des nombre plus petit ou egal a la mediane.
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

void	ft_algorythm(t_list **a, t_list **b, t_list *sorted)
{
	int	median;
	int	i;

	i = 0;
	median = ft_median(sorted);
	while ((*a)->nb <= median)
	{
		ft_pa(a, b);
		i++;
	}
	if ((*a)->next && (*a)->next->nb <= median)
		ft_sa(&(*a)->nb, &(*a)->next->nb);
	else if (ft_scan(*a, median))
		while((*a)->nb > median)
			ft_rra(a);
	if (i != 0)
		ft_algorythm(a, b, sorted);
}
//ft_min : definit le plus petit nombre de la lise placee en parametre
int	ft_min(t_list *lst)
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
//ft_empty_b : renvoie dans la liste a tous les maillons de la liste b dans l'ordre croissant
void	ft_empty_b(t_list **b_stack, t_list **a_stack, t_list *sorted)
{
	if (ft_check_rev_order(*b_stack))
	{
		while (*b_stack)
		{
			ft_pb(b_stack, a_stack);
			ft_rra(&sorted);
		}
	}
	else
	{
		if (!*b_stack || !b_stack)
			return ;
		while ((*b_stack)->nb != ft_lstlast(sorted)->nb)
		{
			ft_reverse_rotate(b_stack);
			write(1, "rra\n", 4);
		}
		ft_push (b_stack, a_stack);
		write(1, "pb\n", 3);
		ft_reverse_rotate (&sorted);
		if (*b_stack)
			ft_empty_b(b_stack, a_stack, sorted);
	}
}

void	ft_algo_three(t_list **a_stack, t_list **b_stack, t_list *sorted)
{
	if (ft_lstlast(sorted)->nb == (*a_stack)->nb)
		ft_ra(a_stack);
	if (sorted->nb == (*a_stack)->next->nb)
		ft_sa(&(*a_stack)->nb, &(*a_stack)->next->nb);
	if (ft_lstlast((*a_stack))->nb == sorted->nb)
	{
		ft_rra(a_stack);
		printf("AAA\n");
	}
	if (ft_lst_cmp(*a_stack, sorted))
	{
		ft_rra(a_stack);
		ft_sa(&(*a_stack)->nb, &(*a_stack)->next->nb);
	}
	if (ft_lst_cmp(*a_stack, sorted))
		ft_algo_three(a_stack, b_stack, sorted);
}