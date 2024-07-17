/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:06:53 by yilin             #+#    #+#             */
/*   Updated: 2024/07/16 18:29:57 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*lst_push: */
static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp_node;
	
	if (!(*src))
		return ;
	tmp_node = *src; //start of src
	// set to the current top node of the source stack => make aside the top space
	*src = (*src)->next;
	// If the new top of the source stack is not NULL, set its prev pointer to NULL
	if (*src)
		(*src)->prev = NULL;
	// Prepare the pushed node by setting its prev pointer to NULL
	tmp_node->prev = NULL;
	// check if dest empty=>Push the node onto the destination stack
	if (!(*dest))
	{
		*dest = tmp_node;
		tmp_node->next = NULL; //set NULL=>the end of stack => only one in the stack
	}
	else
	{
		//not empty=> set tmp_node to connect with dest
		//Set the next pointer of tmp_node to the current top of the destination stack
		tmp_node->next = *dest;
		//Set the previous pointer of the old top node to the pushed node
		(tmp_node->next)->prev = tmp_node;
		//Update the top pointer of the destination stack to the pushed node
		*dest = tmp_node; //update "top of *dest"
	}
}

/*pa: push */
void	pa(t_stack **a, t_stack **b)
{
	if (!(*b))
		return ;
	push(b, a);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
}
/*pb: */
void	pb(t_stack **a, t_stack **b)
{
	if (!(*a))
		return ;
	push(a, b);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

// //prepare to push
// void prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
// {
// 	if (!stack || !top_node)
// 		return ;
// 	while (*stack != top_node)//if stack not first_node => operate on a & b
// 	{
// 		if (stack_name == 'a')
// 		{
// 			if (top_node->above_median)//boolean: top_node IS above meidan
// 				ra(stack);
// 			else
// 				rra(stack);
// 		}
// 		else if (stack_name == 'b')
// 		{
// 			if (top_node->above_median)
// 				rb(stack);
// 			else
// 				rrb(stack);
// 		}
// 	}
// }
