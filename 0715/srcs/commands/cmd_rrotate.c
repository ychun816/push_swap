/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:07:01 by yilin             #+#    #+#             */
/*   Updated: 2024/07/15 14:39:39 by yilin            ###   ########.fr       */
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

	if (!(*stack) ||!(*stack)->next)//Check if the stack is empty, or if there's one node
		return ;
	last_node = get_last_node(*stack);
	if (!(last_node->prev))
		return ;
	(last_node->prev)->next = NULL;//Link last_node to the front
	last_node->next = *stack;//Link last_node to front
	last_node->prev = NULL;//Link last_node to front
	*stack = last_node;// Update the head of the stack to the new node
	(last_node->next)->prev = last_node;// Update the prev pointer of the old head node
}

/*rra: last node become first*/
void	rra(t_stack **a, int repeat)
{
	if (!(*a) || !repeat)
		return ;
	rrotate(a);
	ft_printf("rra\n");// write(STDOUT_FILENO, "rra\n", 4);
	rra(a, repeat - 1);
}
// void	rra(t_stack **a)
// {
// 	rrotate(a);
// 	ft_printf("rra\n");
// }

/*rrb: last node become first*/
void	rra(t_stack **b, int repeat)
{
	if (!(*b) || !repeat)
		return ;
	rrotate(b);
	ft_printf("rrb\n");// write(STDOUT_FILENO, "rrb\n", 4);
	rrb(b, repeat - 1);
}
// void	rrb(t_stack **b)
// {
// 	rrotate(b);
// 	ft_printf("rrb\n");
// }

/*rrr: rra and rrb at the same time*/
void	rrr(t_stack **a, t_stack **b, int repeat)
{
	if (!(*a) || !(*b) || !rep)
		return ;
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");//write(STDOUT_FILENO, "rrr\n", 4);
	rrr(a, b, repeat - 1);
}
// void	rrr(t_stack **a, t_stack **b)
// {
// 	rrotate(a);
// 	rrotate(b);
// 	ft_printf("rrr\n");
// }

/*rrotate both*/
/*rotates both the bottom `a` and `b` nodes to the top of their stacks, 
  if it's the cheapest move*/
void	rrotate_both(t_stack **a, t_stack **b, int repeat1, int repeat2)
{
	if (repeat1 > repeat2)
	{
		rrr(a, b, repeat2);
		rra(a, repeat1 - repeat2);
	}
	else
	{
		rrr(a, b, repeat1);
		rrb(b, repeat2 - repeat1);
	}
}
// void	rrotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
// {
// 	//If the current `b` node is not `a` cheapest node's target node
// 	//and the current `a` node is not the cheapest
// 	while(*a != cheapest_node && *b != cheapest_node->target_node)
// 	{
// 		rrr(a, b);
// 		ft_current_position(*a);
// 		ft_current_position(*b);
// 	} 
// }