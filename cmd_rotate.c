/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:06:57 by yilin             #+#    #+#             */
/*   Updated: 2024/06/29 20:46:39 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
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

//stack operation
t_stack *get_last_node(t_stack **stack)
{
	if (! (*stack))
		return (NULL);
	while (*stack->next)
	{
		*stack = *stack->next;
	}
	return (*stack);
}

//update current position
void	current_position(t_stack *stack)
{
	int	i;
	t_stack	*current;

	i = 0;
	//start frm the head of stack
	current = stack;
	while (current)
	{
		current->position_index = i; // Set the index of the current node
		i++;
		current = current->next; // Move to the next node
	}
}

////////
//rotate: The first element becomes the last one
void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	
	//Check for Empty or Single-Node List
	if (!(*stack) || !(*stack)->next)
		return ;
	//get the last node
	last_node = get_last_node(stack);
	//Link the Last Node to the First Node
	last_node->next = *stack;
	//Update the Head of the Stack
	*stack = (*stack)->next;
	//Set the prev Pointer of the New Head to NULL
	(*stack)->prev = NULLL;
	//Fix the prev Pointer of the Old Head
	(last_node->next)->prev = last_node;
	//Set the next Pointer of the Old Head to NULL
	(last_node->next)->next = NULL;
}

//ra
void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

//rb
void	rb(t_stack **b)
{
	rotate(b);
	write(1,  "rb\n", 3);
}

//rr
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

/*
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

/*rotate both :
simultaneously rotate two stacks (a and b) until one of the stacks reaches a specific node.*/

void rotate_both(t_stack **a, t_stack **b, t_stack *cheapst_node)
{
	t_stack	*target_node;
	
	while(*a != cheapest_node && *b != cheapt_node->target_node)
		rr(a, b);
	current_position(a);
	current_position(b);
}
