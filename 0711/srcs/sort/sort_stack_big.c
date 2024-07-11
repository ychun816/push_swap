/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:23 by yilin             #+#    #+#             */
/*   Updated: 2024/07/11 20:01:57 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "libft/includes/libft.h"

// rotate both
// As long as the current `b` node is not `a` cheapest node's target node,
// and the current top `a` node is not the  node

// rrotate both:
// rotates both the bottom `a` and `b` nodes to the top of their stacks,
// if it's the cheapest move*/

// push a to b:
/*prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`,
until there are 3 nodes left in `a
*/
static void push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node_a; // To store the pointer to the cheapest `a` node

	// get cheapest node
	cheapest_node_a = get_cheapest_node(*a);
	// If both the cheapest `a` node and its target `b` node are above the median
	if (cheapest_node_a->above_median && cheapest_node_a->target_node->above_median)
		//`rrotate_both` => execute if neither nodes are at the top
		rrotate_both(a, b, cheapest_node_a);
	// If both the cheapest `a` node and its target `b` node are below the median
	else if (!(cheapest_node_a->above_median) && !(cheapest_node_a->target_node->above_median))
	{
		// Ensure "cheapest nodes (a)" is at the top, ready for pushing
		prep_for_push(a, cheapest_node_a, 'a');
		// Ensure ""target node (b)" is at the top, ready for pushing
		prep_for_push(b, cheapest_node_a, 'b');
		pb(a, b);
	}
}
// push b to a:
/*prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` */
static void pushback_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a'); // Ensure `b`'s target `a` node is on top of the stack
	pa(a, b);
}

// min on top => move the smallest content on top
static void move_min_to_top(t_stack **a)
{
	t_stack *min_node;

	min_node = get_min_node(*a);
	// As long as the smallest number is not at the top
	while ((*a)->content != min_node->content)
	{
		if (min_node->above_median) // Rotate or reverse rotate according to the position of the node on the median
			ra(a);					// top=>bottom TODO: ra(a, false);
		else						// below median
			rra(a);					// bottom=>top TODO:	rra(a, false);
	}
}

void sort_stack_big(t_stack **a, t_stack **b)
{
	int a_len;

	a_len = ft_stacklen(*a);
	// SORT 5//
	// If stack `a` has more than three nodes and aren't sorted
	if ((a_len--) > 3 && !(is_stack_sorted(*a)))
		pb(a, b);
	// If stack `a` still has more than three nodes and aren't sorted
	if ((a_len--) > 3 && !(is_stack_sorted(*a)))
		pb(a, b);
	// SORT 3//
	sort_stack_3small(a);
	// SORT BIGGER THAN 5//
	// If stack `a` still has more than three nodes and aren't sorted
	while ((a_len--) > 3 && !(is_stack_sorted(*a)))
	{
		prep_node_a(*a, *b); // prep all nodes from both stacks
		push_a_to_b(a, b);	 // push the cheapest `a` nodes into a sorted stack `b`, until three nodes are left in stack `a`
	}
	while (*b) // loop stack b til end
	{
		prep_node_b(*a, *b); // all nodes frm both stacks
		pushback_b_to_a(a, b);	 // push all b nodes back to sorted stack a
	}
	ft_current_position(*a); // update current postion of *a
	move_min_to_top(a);		 // ensure min node on top
}