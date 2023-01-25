/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:56:07 by tbourdea          #+#    #+#             */
/*   Updated: 2023/01/25 09:17:59 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 33
# define PB 35
# define RA 4
# define RB 5
# define RR 9
# define RRA 11
# define RRB 12
# define RRR 23

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

int		ft_max(t_stack *lst);
int		ft_min(t_stack *lst);
int		ft_micro_parsing(char *str);
int		ft_parsing(int ac, char **av);
int		ft_lstsize(t_stack *lst);
int		ft_median(t_stack *lst);
int		ft_scan(int ref, t_stack *lst);
int		ft_check_order(t_stack *lst);
int		ft_check_rev_order(t_stack *lst);
int		ft_good_first(int ref, t_stack *lst, t_stack *sorted);
int		ft_lst_cmp(t_stack *lst_a, t_stack *lst_b);
int		ft_hit_nb(t_stack *current, t_stack *stack);
int		ft_next_move(t_stack *lst);
void	ft_algorythm(t_stack **a, t_stack **b, t_stack **cmd);
void	ft_push(t_stack **from_stack, t_stack **to_stack);
void	ft_rotate(t_stack **lst);
void	ft_reverse_rotate(t_stack **lst);
void	ft_swap(int *a, int *b);
long	ft_atol(char *str);
void	sort_list(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lil_algo(t_stack **a, t_stack **b, t_stack *sorted, t_stack **cmd);
void	ft_algo_three(t_stack **stack, t_stack **cmd);
void	ft_rev_algo_three(t_stack **stack, t_stack **cmd);
void	ft_rrb(t_stack **lst, t_stack **instruction);
void	ft_rra(t_stack **lst, t_stack **instruction);
void	ft_rb(t_stack **lst, t_stack **instruction);
void	ft_ra(t_stack **lst, t_stack **instruction);
void	ft_sa(int *a, int *b, t_stack **instruction);
void	ft_sb(int *a, int *b, t_stack **instruction);
void	ft_sort_a(t_stack **a, t_stack **cmd);
void	ft_empty_b(t_stack **a, t_stack **b, t_stack **cmd);
void	ft_green_light_a(t_stack *stack, t_stack **lst, t_stack **cmd);
void	ft_green_light_a(t_stack *stack, t_stack **lst, t_stack **cmd);
void	ft_pa(t_stack **from_stack, t_stack **to_stack, t_stack **instruction);
void	ft_pb(t_stack **from_stack, t_stack **to_stack, t_stack **instruction);
void	ft_push_up(t_stack **a, t_stack **b, t_stack *sorted, t_stack **cmd);
t_stack	*ft_improve(t_stack **cmd);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int nb);
t_stack	*list_inputs(int ac, char **av);
t_stack	*ft_delone(t_stack *lst);
t_stack	*ft_first_in_b(int ref, t_stack **b);

#endif