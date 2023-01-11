/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:56:07 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/11 20:12:35 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}					t_list;

int		ft_micro_parsing(char *str);
int		ft_parsing(int ac, char **av);
int		ft_lstsize(t_list *lst);
int		ft_median(t_list *lst);
int		ft_scan(t_list *lst, int median);
long	ft_atol(char *str);
void	sort_list(t_list *lst);
void	ft_swap(int *a, int *b);
void	ft_lstadd_front(t_list *lst, t_list *new);
void	ft_lstadd_back(t_list *lst, t_list *new);
void	ft_push(t_list **from_list, t_list **to_list);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);
void	ft_algorythm(t_list **a_stack, t_list **b_stack, t_list **sorted_stack);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int nb);
t_list	*list_inputs(int ac, char **av);

#endif