/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest_b2a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:07:02 by yilin             #+#    #+#             */
/*   Updated: 2024/07/17 17:25:53 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/////// b TO a ///////
/*
 * @param from - The source stack.
 * @param loc - The location of the node in the source stack.
 * @param size - The size of the source stack.
 * @param to - The destination stack.
 * @return The number of steps required.
 */
int	count_step_b2a(t_stack *b, int b_pos, int b_len, t_stack *a)
{
	int	target_content;
	int	target_pos;
	int	a_len;
	int	smaller_pos;
	int	smaller_target_pos;
	
	// Get the target value in the destination stack for the 'from' node's content.
	target_content = set_target_b2a(a, get_content(b));
	target_pos = get_target_position(a, target_content);
	a_len = ft_stacklen(a);
	// Calculate the steps based on the position of the node and target.
	if ((b_len - b_pos) > b_pos && (a_len - target_pos) > target_pos)
	{
		//return (ft_bigger(loc, tar_loc)) 
		if (b_pos > target_pos)
			return (b_pos);
		return (target_pos);
	}
	else if ((b_len - b_pos) < b_pos && (a_len - target_pos) < target_pos)
	{
		//return (ft_bigger(size - loc, ft_lstsize(to) - tar_loc));
		if ((b_len - b_pos) > (a_len - target_pos))
			return ((b_len - b_pos));
		return ((a_len - target_pos));
	}
	else
	{
		// //return (ft_smaller(loc, size - loc)
		// 	+ ft_smaller(tar_loc, ft_lstsize(to) - tar_loc));
		if (b_pos < (b_len) - b_pos)
			smaller_pos = b_pos;
		else
			smaller_pos = b_len - b_pos;
		if (target_pos < (a_len - target_pos))
			smaller_target_pos = target_pos;
		else
			smaller_target_pos = a_len - target_pos;
		return (smaller_pos + smaller_target_pos);
	}
}
/*set cheapest b2a*/
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

/*
 * Find the cheapest node to move from one stack to another.
 * This function is similar to ft_find_cheapest_ab but for a different operation.
 * 
 * @param from - The source stack.
 * @param size - The size of the source stack.
 * @param to - The destination stack.
 * @return The content of the cheapest node to move.
 */
int	get_cheapest_b2a(t_stack *b, int b_len, t_stack *a)
{
	t_stack	*tmp;
	int	cheapest_step;
	int	step;
	int	i;
	
	i = 0;
	// Initialize the temporary pointer to the start of the source stack.
	tmp = b;
	// Calculate the initial cheapest steps for the first node.
	cheapest_step = count_step_b2a(b, i, b_len, a);
	// Iterate through the source stack to find the cheapest node to move.
	while (i < b_len)
	{
		step = count_step_b2a(b, i, b_len, a);
		if (step < cheapest_step)
		{
			cheapest_step = step;
			tmp = b;//Update the temporary pointer to the current node
		}
		i++;
		b = b->next;
	}
	return (get_content(tmp));
}