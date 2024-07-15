/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:23 by yilin             #+#    #+#             */
/*   Updated: 2024/07/15 19:57:21 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push a to b*/
static void push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node_a; // To store the pointer to the cheapest `a` node

	// get cheapest node
	cheapest_node_a = get_cheapest_node(*a);
	// If both the cheapest `a` node and its target `b` node are above the median
	if (cheapest_node_a->above_median && (cheapest_node_a->target_node)->above_median)
		//`rrotate_both` => execute if neither nodes are at the top
		rotate_both(a, b, cheapest_node_a);
	// If both the cheapest `a` node and its target `b` node are below the median
	else if (!(cheapest_node_a->above_median) && !((cheapest_node_a->target_node)->above_median))
		rrotate_both(a, b, cheapest_node_a);//`rev_rotate_both` will execute if neither nodes are at the top
	prep_for_push(a, cheapest_node_a, 'a');// Ensure "cheapest nodes (a)" is at the top, ready for pushing
	prep_for_push(b, cheapest_node_a->target_node, 'b');// Ensure "target node (b)" is at the top, ready for pushing
	pb(a, b);
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
			ra(a);					// top=>bottom
		else						// below median
			rra(a);					// bottom=>top
	}
}

void sort_stack_big(t_stack **a, t_stack **b, int a_len)
{
	int b_len;

	b_len = 0;
	while(b_len < 2)
	{
		pb(a, b);
		b_len++;
	}
	while (a_len - b_len > 3)
	{
		cheap_checka2b(a, a_len - ,b_len b, b_len);
		pb(a, b);
		b_len++;
	}
	sort_stack_3nodes(a);
	while (b_len > 0)
	{
		cheap_checkb2a(b, b_len, a, a_len - b_len);
		pa(b, a);
		b_len--;
	}
	sort_stack_a(a);
}