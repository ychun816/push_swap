/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:06:53 by yilin             #+#    #+#             */
/*   Updated: 2024/07/08 15:06:52 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

/*lst_push: */
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp_node;
	
	//check if src empty
	if (!(*src))
		return ;
	// Pop the top node from the source stack
	tmp_node = *src; //start of src
	// set to the current top node of the source stack => make aside the top space
	*src = (*src)->next;
	// If the new top of the source stack is not NULL, set its prev pointer to NULL
	if (*src)
		(*src)->prev-> = NULL;
	// Prepare the pushed node by setting its prev pointer to NULL
	tmp_node->prev = NULL;
	// check if dest empty
	//empty =>Push the node onto the destination stack
	if (!(*dest))
	{
		*dest = tmp_node;
		tmp_node->next = NULL; //set NULL=>the end of stack => only one in the stack
	}
	//not empty=> set tmp_node to connect with dest
	else
	{
		//Set the next pointer of tmp_node to the current top of the destination stack
		tmp_node->next = *dest;
		//Set the previous pointer of the old top node to the pushed node
		(tmp_node->next)->prev = tmp_node;
		//Update the top pointer of the destination stack to the pushed node
		*dest = tmp_node; //update "top of *dest"
	}
}


/*pa: push */
// This would only modify local copies of dst and src
// Any changes to dst and src here won't affect the original
void	pa(t_stack a, t_stack b) TODO: //pa(t_stack_node **a, t_stack_node **b, bool print) 
{
	push(b, a);
	ft_printf("pa\n");
}
/*pb: */
void	pb(t_stack a, t_stack b) TODO: //pb(t_stack_node **a, t_stack_node **b, bool print) 
{
	push(a, b);
	ft_printf("pb\n");
}

//prepare to push
void prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	//if stack not first_node => operate on a & b
	while (!stack && stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median) //boolean: top_node IS above meidan
				ra(stack); TODO: OR: ra(stack, false);
			else
				rra(stack); TODO: OR: rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack); TODO: OR: rb(stack, false);
			else
				rrb(stack); TODO: OR: rrb(stack, false);
		}
	}
}
