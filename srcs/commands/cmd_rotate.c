/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:06:57 by yilin             #+#    #+#             */
/*   Updated: 2024/07/21 18:44:55 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
***rotate: The first element becomes the last one***

//Initial List
stack -> [1] <-> [2] <-> [3] <-> [4] -> NULL

//After Finding the Last Node
last_node -> [4]
stack -> [1] <-> [2] <-> [3] <-> [4] -> NULL

//Linking the Last Node to the First Node
{last_node} -> [4] -> [1] <-> [2] <-> [3] <-> [4] -> [1] (circular reference)
stack -> [1] <-> [2] <-> [3] <-> [4] -> [1] (circular reference)

//Updating the Head of the Stack
stack -> [2] <-> [3] <-> [4] -> [1] (circular reference)

//Setting the prev Pointer of the New Head to NULL
stack -> [2] <-> [3] <-> [4] -> [1] (circular reference)
       ^
       |
      NULL

//After Setting the next Pointer of the Old Head to NULL
stack -> [2] <-> [3] <-> [4] -> [1] -> NULL
       ^
       |
      NULL
*/
static void	rotate(t_stack **stack)
{
	t_stack	*og_head;

	if (!(*stack) || !(*stack)->next)
		return ;
	og_head = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	og_head->next = NULL;
	og_head->prev = NULL;
	ft_stackadd_back(stack, og_head);
}

/*ra*/
void	ra(t_stack **a, int repeat)
{
	if (!(*a) || !repeat)
		return ;
	rotate(a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	ra(a, repeat - 1);
}

/*rb*/
void	rb(t_stack **b, int repeat)
{
	if (!(*b) || !repeat)
		return ;
	rotate(b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	rb(b, repeat - 1);
}

/*rr*/
void	rr(t_stack **a, t_stack **b, int repeat)
{
	if (!(*a) || !(*b) || !repeat)
		return ;
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
	rr(a, b, repeat - 1);
}

/*
***rotate both: ***
simultaneously rotate two stacks (a and b),
until one of the stacks reaches a specific node.

The loop will keep rotating both stacks until:
The head of stack b becomes cheapst_node->target.
The head of stack a becomes cheapst_node

Before rotate
Stack a: [1] <-> [2] <-> [3]
Stack b: [4] <-> [5] <-> [6]

After a few rotations,
Stack a: [2] <-> [3] <-> [1] (if cheapst_node was initially [1])
Stack b: [5] <-> [6] <-> [4] (if cheapst_node->target was initially [4])
*/
void	rotate_both(t_stack **a, t_stack **b, int repeat_a, int repeat_b)
{
	if (repeat_a > repeat_b)
	{
		rr(a, b, repeat_b);
		ra(a, repeat_a - repeat_b);
	}
	else
	{
		rr(a, b, repeat_a);
		rb(b, repeat_b - repeat_a);
	}
}
