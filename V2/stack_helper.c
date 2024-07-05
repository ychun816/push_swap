/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:44:49 by yilin             #+#    #+#             */
/*   Updated: 2024/07/05 15:14:09 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

/* ft_stack_last : get_last_stack*/
/*
stack structure:
head -> [data | next] -> [data | next] -> [data | NULL]
*/
t_stack	ft_node_last(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

/*update current position*/
void	ft_node_current_pos(t_stack *stack)
{
	int	i;
	t_stack	*current;

	i = 0;
	/*start frm the head of stack*/
	current = stack;
	while (current)
	{
		current->position_index = i; //Set the index of the current node
		i++;
		current = current->next; //Move to the next node
	}
}
/*ft_stacklen*/
int	ft_stacklen(t_stack **stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;	
	}
	return (len);
}

/*ft__cheapest*/

/*init_node_a: prepare nodes to push "a" to "b"*/

/*init_node_b: prepare nodes to push "b" to "a"*/

