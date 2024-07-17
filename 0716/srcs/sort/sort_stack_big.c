/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:23 by yilin             #+#    #+#             */
/*   Updated: 2024/07/16 21:46:38 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*push a to b*/
// static void push_a_to_b(t_stack **a, t_stack **b)
// {
// 	t_stack *cheapest_node_a; // To store the pointer to the cheapest `a` node

// 	// get cheapest node
// 	cheapest_node_a = get_cheapest_node(*a);
// 	// If both the cheapest `a` node and its target `b` node are above the median
// 	if (cheapest_node_a->above_median && (cheapest_node_a->target_node)->above_median)
// 		//`rrotate_both` => execute if neither nodes are at the top
// 		rotate_both(a, b, cheapest_node_a);
// 	// If both the cheapest `a` node and its target `b` node are below the median
// 	else if (!(cheapest_node_a->above_median) && !((cheapest_node_a->target_node)->above_median))
// 		rrotate_both(a, b, cheapest_node_a);//`rev_rotate_both` will execute if neither nodes are at the top
// 	prep_for_push(a, cheapest_node_a, 'a');// Ensure "cheapest nodes (a)" is at the top, ready for pushing
// 	prep_for_push(b, cheapest_node_a->target_node, 'b');// Ensure "target node (b)" is at the top, ready for pushing
// 	pb(a, b);
// }
// // push b to a:
// /*prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` */
// static void pushback_b_to_a(t_stack **a, t_stack **b)
// {
// 	prep_for_push(a, (*b)->target_node, 'a'); // Ensure `b`'s target `a` node is on top of the stack
// 	pa(a, b);
// }

// // min on top => move the smallest content on top
// static void move_min_to_top(t_stack **a)
// {
// 	t_stack *min_node;

// 	min_node = get_min_node(*a);
// 	// As long as the smallest number is not at the top
// 	while ((*a)->content != min_node->content)
// 	{
// 		if (min_node->above_median) // Rotate or reverse rotate according to the position of the node on the median
// 			ra(a);					// top=>bottom
// 		else						// below median
// 			rra(a);					// bottom=>top
// 	}
// }

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
		set_cheapest_a2b(a, (a_len - b_len), b, b_len);
		pb(a, b);
		b_len++;
	}
	sort_stack_3nodes(a);
	while (b_len > 0)
	{
		set_cheapest_b2a(b, b_len, a, (a_len - b_len));
		pa(b, a);
		b_len--;
	}
	sort_stack_a(a);
}

/*set cheapest a2b*/
void set_cheapest_a2b(t_stack **a, int a_len, t_stack **b, int b_len)
{
    t_stack *cheapest_node;
    t_stack *target_node;
    int cheapest_position;
    int target_position;

    // Find the cheapest node in stack 'a'
    cheapest_node = *a;
    while (cheapest_node && !cheapest_node->cheapest)
        cheapest_node = cheapest_node->next;
    // If no cheapest node is found, exit the function
    if (!cheapest_node)
        return ;
    // Find the target node in stack 'b'
    target_node = *b;
    while (target_node && target_node != cheapest_node->target_node)
        target_node = target_node->next;
    // If no target node is found, exit the function
    if (!target_node)
        return ;
    // Determine the positions of the cheapest node and the target node
    cheapest_position = cheapest_node->position_index;
    target_position = target_node->position_index;
    // Calculate the cost of rotations
    if (a_len - cheapest_position > cheapest_position && b_len - target_position > target_position)
        rotate_both(a, b, cheapest_position, target_position);
    else if (a_len - cheapest_position < cheapest_position && b_len - target_position < target_position)
        rrotate_both(a, b, (a_len - cheapest_position), (b_len - target_position));
    else
    {
        if (b_len - target_position > target_position)
            rb(b, target_position);
        else
            rrb(b, b_len - target_position);

        if (a_len - cheapest_position > cheapest_position)
            ra(a, cheapest_position);
        else
            rra(a, (a_len - cheapest_position));
    }
}

void set_cheapest_b2a(t_stack **b, int b_len, t_stack **a, int a_len)
{
    t_stack *cheapest_node;
    t_stack *target_node;
    int cheapest_position;
    int target_position;

    // Find the cheapest node in stack 'b'
    cheapest_node = *b;
    while (cheapest_node && !cheapest_node->cheapest)
        cheapest_node = cheapest_node->next;
    // If no cheapest node is found, exit the function
    if (!cheapest_node)
        return;
    // Find the target node in stack 'a'
    target_node = *a;
    while (target_node && target_node != cheapest_node->target_node)
        target_node = target_node->next;
    // If no target node is found, exit the function
    if (!target_node)
        return;
    // Determine the positions of the cheapest node and the target node
    cheapest_position = cheapest_node->position_index;
    target_position = target_node->position_index;
    // Calculate the cost of rotations
    if (b_len - cheapest_position > cheapest_position && a_len - target_position > target_position)
        rotate_both(a, b, target_position, cheapest_position);
    else if (b_len - cheapest_position < cheapest_position && a_len - target_position < target_position)
        rrotate_both(a, b, (a_len - target_position), (b_len - cheapest_position));
    else
    {
        if (a_len - target_position > target_position)
            ra(a, target_position);
        else
            rra(a, a_len - target_position);

        if (b_len - cheapest_position > cheapest_position)
            rb(b, cheapest_position);
        else
            rrb(b, (b_len - cheapest_position));
    }
}