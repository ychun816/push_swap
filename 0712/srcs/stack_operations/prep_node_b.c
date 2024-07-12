/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:20:41 by yilin             #+#    #+#             */
/*   Updated: 2024/07/10 20:32:25 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/includes/libft.h"

//ft_current_position
//set target b
static void	set_target_node_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack *target_node;
	long	best_match_content;

	while (b)
	{
		best_match_content = LONG_MAX; //Set the current best match to the max long
		current_a = a;
		while (current_a)
		{
			if ((current_a->content) > (b->content) && (current_a->content) < best_match_content)
			{
				best_match_content = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_content == LONG_MAX) //If the best match value has not changed
			b->target_node = get_min_node(a); //Set `b` node's target node pointer to point to the smallest number in stack `a`
		else
			b->target_node = target_node; //If the best match value has been updated, then we have a target node for the current `b` node
		b = b->next;
	}
}

//handle_node_b
void	prep_node_b(t_stack *a_node, t_stack *b_node)
{
	ft_current_position(a_node);
	ft_current_position(b_node);
	set_target_node_b(a_node, b_node);
}