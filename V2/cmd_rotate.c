/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:06:57 by yilin             #+#    #+#             */
/*   Updated: 2024/07/04 19:52:51 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

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

//rotate: The first element becomes the last one
void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	
	//Check for Empty or Single-Node List
	if (!(*stack) || !(*stack)->next)
		return ;
	//get the last node
	last_node = ft_stack_last(stack);
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
	ft_printf("ra\n");
}

//rb
void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

//rr
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
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
	ft_current_position(a);
	ft_current_position(b);
}