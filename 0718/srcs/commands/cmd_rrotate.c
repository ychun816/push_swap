/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:01 by yilin             #+#    #+#             */
/*   Updated: 2024/07/17 17:01:17 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*rrotate (reverse rotate)*/
/*
(1)Get last_node
Head                  last_node => get_last_node(**stack)
 ↓                       ↓
[A] <-> [B] <-> [C] <-> [D]
----------------------------
(2)Detach last_node:
Head
 ↓
[A] <-> [B] <-> [C]    [D] => deatch last_node => (last_node->prev)->next = NULL;
---------------------------
(3)Link last_node to front:
               (*stack)
NULL <-> [D] <-> [A] <-> [B] <-> [C] <-> NULL
----------------------------
(4)Update:

Head
 ↓
[D] <-> [A] <-> [B] <-> [C]
*/
static void	rrotate(t_stack **stack)
{
	t_stack *last_node;
	t_stack	*second_last_node;

	if (!(*stack) ||!(*stack)->next)//Check if the stack is empty, or if there's one node
		return ;

	// Find the last and second-to-last nodes
	last_node = *stack;
	while (last_node->next)
	{
		second_last_node = last_node;
		last_node = last_node->next;
	}
	second_last_node->next = NULL;// Remove the last node from the end
	// Move the last node to the front
	last_node->next = *stack;
	last_node->prev = NULL;
	(*stack)->prev = last_node;
	*stack = last_node;// Update the head of the stack
}
// static void	rrotate(t_stack **stack)
// {
// 	t_stack *last_node;

// 	if (!(*stack) ||!(*stack)->next)//Check if the stack is empty, or if there's one node
// 		return ;
// 	ft_stackadd_back(stack, last_node);
// 	// last_node = ft_stackadd_back(*stack);
// 	if (!(last_node->prev))
// 		return ;
// 	(last_node->prev)->next = NULL;//Link last_node to the front
// 	last_node->next = *stack;//Link last_node to front
// 	last_node->prev = NULL;//Link last_node to front
// 	*stack = last_node;// Update the head of the stack to the new node
// 	(last_node->next)->prev = last_node;// Update the prev pointer of the old head node
// }

/*rra: last node become first*/
void	rra(t_stack **a, int repeat)
{
	if (!(*a) || !repeat)
		return ;
	rrotate(a);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
	rra(a, repeat - 1);
}

/*rrb: last node become first*/
void	rrb(t_stack **b, int repeat)
{
	if (!(*b) || !repeat)
		return ;
	rrotate(b);
	ft_putstr_fd("rrb\n", STDOUT_FILENO);
	rrb(b, repeat - 1);
}

/*rrr: rra and rrb at the same time*/
void	rrr(t_stack **a, t_stack **b, int repeat)
{
	if (!(*a) || !(*b) || !repeat)
		return ;
	rrotate(a);
	rrotate(b);
	ft_putstr_fd("rrr\n", STDOUT_FILENO);
	rrr(a, b, repeat - 1);
}

/*rrotate both*/
/*rotates both the bottom `a` and `b` nodes to the top of their stacks, 
  if it's the cheapest move*/
void	rrotate_both(t_stack **a, t_stack **b, int repeat_a, int repeat_b)
{
	if (repeat_a > repeat_b)
	{
		rrr(a, b, repeat_b);
		rra(a, repeat_a - repeat_b);
	}
	else
	{
		rrr(a, b, repeat_a);
		rrb(b, repeat_b - repeat_a);
	}
}
