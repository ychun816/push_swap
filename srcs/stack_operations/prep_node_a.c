/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:20:37 by yilin             #+#    #+#             */
/*   Updated: 2024/07/10 20:32:20 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/includes/libft.h"

//ft_current_position
//set target a
static void	set_target_node_a(t_stack *a, t_stack *b) // Find `a` node's target in stack `b`
{
	t_stack	*current_b; // To store the pointer to the current node in stack `b` and iterate through each node following
	t_stack *target_node; // To store the pointer to the target node in stack `b`
	long	best_match_content;  // Stores the value of the "closest smaller number" so far

	while (a)
	{
		best_match_content = LONG_MIN; // Assign the smallest `long` as the closest smaller number so far
		current_b = b; // Assign to `current_b` the current `b` node
		while (current_b) // Iteratively search through all the nodes in stack `b` til end
		{
			// Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			if ((current_b->content) < (a->content) && (current_b->content) > best_match_content)
			{
				best_match_content = current_b->content; // => update the value of the closest smaller number so far
				target_node = current_b; // Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next;
		}
		if ( best_match_content == LONG_MIN) // Check if the LONG_MIN hasn't changed (means we haven't found anything smaller)
			a->target_node = get_max_node(b); //=>find the biggest `content` and set this as the target node
		else //else => // If no "closer smaller number" is found, and the best match has changed
			a->target_node = target_node;// If no "closer smaller number" is found, and the best match has changed
        a = a->next;
	}
}

//count_cost_a
static void	count_cost_a(t_stack *a, t_stack *b)
{
	int	a_len;
	int	b_len;

	//initialize a and b stack
	a_len = ft_stacklen(a);
	b_len = ft_stacklen(b);
	while(a) //loop a
	{
		// Assign the current `a` node's push cost, its index value
		a->push_cost = a->content;
		//Check if the above_median data is FALSE =>below median
		if (a->above_median == false) //!(a->above_median)
			// If false => update `a` node's push cost to: (the stack's length - index)
			a->push_cost = a_len - (a->content);
		// Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
		if ((a->target_node)->above_median == true) //a->above_median
			//if true => update `a` node's push cost to: the sum of (its current index) + (its target `b` node's index)
			a->push_cost = (a->push_cost) + a->target_node->content;
		else // else =>If `a` node is indeed above median and its target `b` node is below median
			// Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
			a->push_cost = (a->push_cost) + (b_len - a->target_node->content);
		// Move to the next `a` node for its cost analysis
		a = a->next;
	}
}

//init_node_a
void	prep_node_a(t_stack *a_node, t_stack *b_node)
{
	ft_current_position(a_node);
	ft_current_position(b_node);
	set_target_node_a(a_node, b_node);
	count_cost_a(a_node, b_node);
	set_cheapest_node(a_node);
}
