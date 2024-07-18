/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:06:57 by yilin             #+#    #+#             */
/*   Updated: 2024/07/17 16:53:02 by yilin            ###   ########.fr       */
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
	// t_stack	*last_node;
	
	if (!(*stack) || !(*stack)->next)//Check for Empty or Single-Node List
		return ;
	og_head = *stack;// Store the first node
	*stack = (*stack)->next;//Update head to the next node
	(*stack)->prev = NULL;//Set prev of new head to NULL
	
	og_head->next = NULL;//Extract/Isolate the old head node
	og_head->prev = NULL; //Detach og_head from the start of the list
	ft_stackadd_back(stack, og_head);// Add og_head to the back of the list
	// last_node = ft_stackadd_back(stack, og_head);
	// last_node->next = og_head;//Attach the old head node to the back
	// og_head->prev = last_node;
}

/*ra*/
void	ra(t_stack **a, int repeat)
{
	if (!(*a) || !repeat)
		return;
	rotate(a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	ra(a, repeat - 1);// Recursively call ft_ra with rep decremented by 1
}

/*rb*/
void	rb(t_stack **b, int repeat)
{
	if (!(*b) || !repeat)
		return;
	rotate(b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	rb(b, repeat - 1);// Recursively call ft_ra with rep decremented by 1
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
simultaneously rotate two stacks (a and b) until one of the stacks reaches a specific node.

The loop will keep rotating both stacks until:
The head of stack b becomes cheapst_node->target_node.
The head of stack a becomes cheapst_node

Before rotate
Stack a: [1] <-> [2] <-> [3]
Stack b: [4] <-> [5] <-> [6]

After a few rotations,
Stack a: [2] <-> [3] <-> [1] (if cheapst_node was initially [1])
Stack b: [5] <-> [6] <-> [4] (if cheapst_node->target_node was initially [4])
*/
void rotate_both(t_stack **a, t_stack **b, int repeat_a, int repeat_b)
{
	if (repeat_a > repeat_b)
	{
		rr(a, b, repeat_b);// Perform repeat2 simultaneous rotations on both stacks
		ra(a, repeat_a - repeat_b);// Perform the remaining rotations on the 'src(a)' stack
	}
	else
	{
		rr(a, b, repeat_a);// Perform repeat1 simultaneous rotations on both stacks
		rb(b, repeat_b - repeat_a);// Perform the remaining rotations on the 'b' stack
	}
}