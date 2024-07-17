/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest_a2b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:02:51 by yilin             #+#    #+#             */
/*   Updated: 2024/07/17 16:20:55 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/////// a TO b /////// 
/*
 * Calculate the number of steps required to move a node from one stack to another.
 * 
 * @param from - The source stack.
 * @param loc - The location of the node in the source stack.
 * @param size - The size of the source stack.
 * @param to - The destination stack.
 * @return The number of steps required.
 */
int	count_step_a2b(t_stack *a, int a_pos, int a_len, t_stack *b)
{
	int	target_content;
	int	target_pos;
	int	b_len;
	int	smaller_pos;
	int	smaller_target_pos;
	
	// Get the target value in the destination stack for the 'from' node's content.
	target_content = set_target_a2b(b, get_content(a));
	target_pos = get_target_position(b, target_content);
	b_len = ft_stacklen(b);
	// Calculate the steps based on the position of the node and target.
	if ((a_len - a_pos) > a_pos && (b_len - target_pos) > target_pos)
	{
		//return (ft_bigger(loc, tar_loc)) 
		if (a_pos > target_pos)
			return (a_pos);
		return (target_pos);
	}
	else if ((a_len - a_pos) < a_pos && (b_len - target_pos) < target_pos)
	{
		//return (ft_bigger(size - loc, ft_lstsize(to) - tar_loc));
		if ((a_len - a_pos) > (b_len - target_pos))
			return ((a_len - a_pos));
		return ((b_len - target_pos));
	}
	else
	{
		// //return (ft_smaller(loc, size - loc)
		// 	+ ft_smaller(tar_loc, ft_lstsize(to) - tar_loc));
		if (a_pos < (a_len - a_pos))
			smaller_pos = a_pos;
		else
			smaller_pos = a_len - a_pos;
		if (target_pos < (b_len - target_pos))
			smaller_target_pos = target_pos;
		else
			smaller_target_pos = b_len - target_pos;
		return (smaller_pos + smaller_target_pos);
	}
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

/*
 * Find the cheapest node to move from one stack to another.
 * 
 * @param from - The source stack.
 * @param size - The size of the source stack.
 * @param to - The destination stack.
 * @return The content of the cheapest node to move.
 */
int	get_cheapest_a2b(t_stack *a, int a_len, t_stack *b)
{
	t_stack *tmp;
	int	cheapest_step;
	int	step;
	int	i;
	
	i = 0;
	// Initialize the temporary pointer to the start of the source stack.
	tmp = a;
	// Calculate the initial cheapest steps for the first node.
	cheapest_step = count_step_a2b(a, i, a_len, b);
	// Iterate through the source stack to find the cheapest node to move.
	while (i < a_len)
	{
		step = count_step_a2b(a, i, a_len, b);
		if (step < cheapest_step)
		{
			cheapest_step = step;
			tmp = a;//Update the temporary pointer to the current node
		}
		i++;
		a = a->next;
	}
	return (get_content(tmp));
}