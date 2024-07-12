/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:03:22 by yilin             #+#    #+#             */
/*   Updated: 2024/07/10 20:41:23 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

/************ STRUCTURE ***********/
typedef enum e_error
{
	FALSE = 1,
	TRUE = 0,	
}	t_error;

typedef struct s_stack
{
	int	content;  //The number to sort
	int	position_index; //The number's position in the stack
	int	push_cost; //How many commands in total
	bool	above_median; /*median 中位数*/ //Used to calculate `push_cost`
	bool	cheapest; //The node that is the cheapest to do commands
	struct	s_stack *prev;
	struct	s_stack	*next;
	struct	s_stack	*target_node;
}	t_stack;

/************ FUNCTIONS ***********/

/***BASIC COMMAND***/
/*push*/
// static void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
/*swap*/
// static void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
/*rotate*/
// static void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
/*rrotate*/
// static void	rrotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rrotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

/***CHECK ERROR & FREE***/
/*check error*/
bool	is_stack_sorted(t_stack *node);
bool	is_syntax_error(char *str);
bool	is_duplicate_error(t_stack	*stack, int content);
/*free and exit*/
void	free_stack(t_stack **stack);
void	exit_program(t_stack **stack, char *error_msg);

/***PREP NODE***/
void	prep_node_a(t_stack *a_node, t_stack *b_node);
void	prep_node_b(t_stack *a_node, t_stack *b_node);

/***STACK HELPER FUNCTIONS***/
int	ft_stacklen(t_stack *node);
void	ft_current_position(t_stack *node);
t_stack	*get_last_node(t_stack *node);
void	set_cheapest_node(t_stack *node);
t_stack	*get_cheapest_node(t_stack *node);
t_stack	*get_max_node(t_stack *node);
t_stack	*get_min_node(t_stack *node);

/***SORT STACK***/
void	avs_to_stack_a(t_stack	**stack_a, char **avs);
void	sort_stack_3small(t_stack **stack);
void sort_stack_big(t_stack * *a, t_stack * *b);

#endif
