/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:03:22 by yilin             #+#    #+#             */
/*   Updated: 2024/07/22 17:43:18 by yilin            ###   ########.fr       */
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
	int				push_cost;
	bool			above_median;
	bool			cheapest;
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
void	a2b_ra_or_rra(t_stack **a, int cheapest_pos, int a_len);
void	a2b_rb_or_rrb(t_stack **b, int trgt_pos, int b_len);
void	b2a_ra_or_rra(t_stack **a, int cheapest_pos, int a_len);
void	b2a_rb_or_rrb(t_stack **b, int trgt_pos, int b_len);
/*RROTATE*/
void	rra(t_stack **a, int repeat);
void	rrb(t_stack **b, int repeat);
void	rrr(t_stack **a, t_stack **b, int repeat);
void	rrotate_both(t_stack **a, t_stack **b, int repeat_a, int repeat_b);

/********** SORT **********/
/*SORT HELPER*/
int		set_target_a2b(t_stack *node, int ref_content);
int		set_target_b2a(t_stack *node, int ref_content);
void	push_check_b2a(t_stack **b, t_stack **a);
void	sort_stack_a(t_stack **a);
/*SORT BIG*/
void	sort_stack_big(t_stack **a, t_stack **b, int a_len);
/*SORT SMALL*/
void	sort_stack_3nodes(t_stack **a);
void	sort_stack_small(t_stack **a, t_stack **b, int n_nodes);

/********** STACK OPERATIONS **********/
/*AVS PUT TO STACK*/
void	avs_to_stack_a(t_stack	**a, int ac, char **av,
			void (*clear_content)(void *));
/*CHECK ERROR*/
char	**check_av_input(int ac, char **av);
bool	is_stack_to_sort(t_stack *node);
bool	is_stack_to_rotate(t_stack *node, int target_content);
/*CLEANUP FUNCTION*/
void	clear(void *content);
void	clear_stack(t_stack **stack, void (*clear)(void *));
void	clear_both_stacks(t_stack **a, t_stack **b);
void	free_strs(char **strs);
/* GET CHEAPEST A TO B*/
int		count_step_a2b(t_stack *a, int a_pos, int a_len, t_stack *b);
void	set_cheapest_a2b(t_stack **a, int a_len, t_stack **b, int b_len);
int		get_cheapest_a2b(t_stack *a, int a_len, t_stack *b);
/* GET CHEAPEST B TO A*/
int		count_step_b2a(t_stack *b, int b_pos, int b_len, t_stack *a);
void	set_cheapest_b2a(t_stack **b, int b_len, t_stack **a, int a_len);
int		get_cheapest_b2a(t_stack *b, int b_len, t_stack *a);
/*STACK HELPER*/
int		ft_stacklen(t_stack *node);
void	ft_stackadd_back(t_stack **stack, t_stack *new_node);
void	ft_stackdelone(t_stack *node, void (*del)(void *));
int		get_content(t_stack *node);
int		get_max_content(t_stack *node);
int		get_min_content(t_stack *node);
int		get_target_position(t_stack *node, int target_content);
int		get_pos_bigger(int pos_x, int pos_y);
int		get_pos_smaller(int pos_x, int pos_y);
t_stack	*find_cheapest_node(t_stack *stack);
t_stack	*find_target_node(t_stack *stack, t_stack *target);

#endif
