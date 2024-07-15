/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:20:37 by yilin             #+#    #+#             */
/*   Updated: 2024/07/13 21:15:23 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***set target a***/
static void	set_target_node_a(t_stack *a, t_stack *b) // Find `a` node's target in stack `b`
{
	t_stack	*current_b; // To store the pointer to the current node in stack `b` and iterate through each node following
	// t_stack *target_node; // To store the pointer to the target node in stack `b`
	long	closest_smaller_content;  // Stores the value of the "closest_smaller_content" so far

	while (a)
	{
		//guarantee any valid content from stack b is larger than this initial value
		//ensure the first valid node found =>smaller than the current node in stack a =>the initial candidate for the "closest_smaller_content smaller" node
		closest_smaller_content = LONG_MIN;
		current_b = b; // Assign to `current_b` the current `b` node
		while (current_b) // Iteratively search through all the nodes in stack `b` til end
		{
			// Check if `b` node is smaller than `a` node && bigger than the closest_smaller_content so far
			if ((current_b->content) < (a->content) && (current_b->content) > closest_smaller_content)
			{
				closest_smaller_content = current_b->content; // => update the value of the closest_smaller_content so far
				a->target_node = current_b; // Update target_node to the current best match
			}
			current_b = current_b->next;
		}
		if (closest_smaller_content == LONG_MIN) // Check if the LONG_MIN hasn't changed (means we haven't found anything smaller)
			a->target_node = get_max_node(b); //=>find the biggest `content` and set this as the target node
		// else //else => // If no "closest_smaller_contentr" is found, and the best match has changed
		// 	a->target_node = target_node;// If no "closest_smaller_content" is found, and the best match has changed
        a = a->next;
	}
}

//count_cost_a
static void	count_cost_a(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	a_len = ft_stacklen(a);/*calculate the total number of nodes in stack a*/
	b_len = ft_stacklen(b);
	while(a)
	{
		a->push_cost = a->position_index;/*Assign [a node]'s push cost == index value*/
		if (!(a->above_median))/*Check if below median*/
			a->push_cost = a_len - (a->position_index);/*a_len == number of nodes in stack a*/
		/*Check if [a node]'s [target b node] ABOVE median attribute => [target b node] ABOVE median*/
		if ((a->target_node)->above_median)/*Check if [a node] ABOVE median*/
			/*=>Set [a node]'s push cost to: sum of ([a node] current index) + (its [target b node]'s index)*/
			a->push_cost = (a->push_cost) + a->target_node->position_index;
		else /*If [a node] ABOVE median && its [target b node] BELOW median*/
			/*=>Set [a node]'s push cost to: sum of ([a node] current index) + ([b_len] - its [target b node]'s index)*/
			a->push_cost = (a->push_cost) + (b_len - a->target_node->position_index);
		a = a->next;
	}
}

/*prep node a*/
void	prep_node_a(t_stack *a_node, t_stack *b_node)
{
	ft_current_position(a_node);
	ft_current_position(b_node);
	set_target_node_a(a_node, b_node);
	count_cost_a(a_node, b_node);
	set_cheapest_node(a_node);
}
