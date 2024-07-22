/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pos_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:44:49 by yilin             #+#    #+#             */
/*   Updated: 2024/07/21 18:45:14 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*get target position*/
int	get_target_position(t_stack *node, int target_content)
{
	int	target_position;

	target_position = 0;
	while (node && node->content != target_content)
	{
		target_position++;
		node = node->next;
	}
	return (target_position);
}

/*(get cheapest a2b/b2a: return bigger)*/
int	get_pos_bigger(int pos_x, int pos_y)
{
	if (pos_x > pos_y)
		return (pos_x);
	return (pos_y);
}

/*(get cheapest a2b/b2a: return smaller)*/
int	get_pos_smaller(int pos_x, int pos_y)
{
	if (pos_x < pos_y)
		return (pos_x);
	return (pos_y);
}

/*(get cheapest a2b/b2a): find_cheapest_node*/
t_stack	*find_cheapest_node(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/*(get cheapest a2b/b2a): find_target_node*/
t_stack	*find_target_node(t_stack *stack, t_stack *target)
{
	while (stack)
	{
		if (stack == target)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
