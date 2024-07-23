/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:03:22 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 19:27:26 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <errno.h>

/* ************************************************************************** */
/*                                STRUCTURE                                   */
/* ************************************************************************** */

typedef enum e_error
{
	FALSE = 1,
	TRUE = 0,	
}	t_error;

typedef struct s_stack
{
	int				content;
	int				pos_ind;
	struct s_stack	*prev;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

/* ************************************************************************** */
/*                                FUNCTIONS                                   */
/* ************************************************************************** */

/********** BASIC COMMAND **********/
/*PUSH*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
/*SWAP*/
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
/*ROTATE*/
void	ra(t_stack **a, int repeat);
void	rb(t_stack **b, int repeat);
void	rr(t_stack **a, t_stack **b, int repeat);
void	rotate_both(t_stack **a, t_stack **b, int repeat_a, int repeat_b);
/*RROTATE*/
void	rra(t_stack **a, int repeat);
void	rrb(t_stack **b, int repeat);
void	rrr(t_stack **a, t_stack **b, int repeat);
void	rrotate_both(t_stack **a, t_stack **b, int repeat_a, int repeat_b);

/********** SORT **********/
/*SORT SMALL*/
void	check_pushback_b2a(t_stack **b, t_stack **a);
void	sort_stack_3nodes(t_stack **a);
void	sort_stack_small(t_stack **a, t_stack **b, int n_nodes);
/*SORT BIG*/
void	sort_stack_a(t_stack **a);
void	sort_stack_big(t_stack **a, t_stack **b, int a_len);
/*CHECK CHEAP A2B*/
int		ft_target_a2b(t_stack *node, int ref);
int		cal_steps_a2b(t_stack *a, int a_pos, int b_len, t_stack *b);
int		find_cheapest_a2b(t_stack *a, int a_len, t_stack *b);
void	check_cheap_a2b(t_stack **from, int size, t_stack **to, int to_size);
/*CHECK CHEAP B2A*/
int		ft_target_b2a(t_stack *node, int ref);
int		cal_steps_b2a(t_stack *b, int pos, int b_len, t_stack *a);
int		find_cheapest_b2a(t_stack *b, int b_len, t_stack *a);
void	check_cheap_b2a(t_stack **from, int size, t_stack **to, int to_size);
/*TARGET HELPER*/
int		get_pos(t_stack *node, int target);
int		ft_bigger(int x, int y);
int		ft_smaller(int x, int y);
bool	is_stack_to_rotate(t_stack *node, int target_content);

/********** STACK OPERATIONS **********/
/*AVS PUT TO STACK*/
void	avs_to_stack_a(t_stack	**a, int ac, char **av);
/*CHECK ERROR*/
char	**check_av_input(int ac, char **av);
bool	is_stack_to_sort(t_stack *node);
bool	is_stack_to_rotate(t_stack *node, int target_content);
/*CLEANUP FUNCTION*/
void	clear(void *content);
void	clear_stack(t_stack **stack, void (*clear)(void *));
void	clear_both_stacks(t_stack **a, t_stack **b);
void	free_strs(char **strs);
/*STACK HELPER*/
int		ft_stacklen(t_stack *node);
void	ft_stackadd_back(t_stack **stack, t_stack *new_node);
int		get_content(t_stack *node);
int		get_max_content(t_stack *node);
int		get_min_content(t_stack *node);

#endif
