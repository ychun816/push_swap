/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:33:48 by yilin             #+#    #+#             */
/*   Updated: 2024/07/22 19:45:38 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*set_target_ab*/
/*
- Initialize target with the minimum value in the stack
- If all values in the stck are bigger than the reference value
- return the max value
- Traverse the stack to find "the biggest value" > ref content
*/
int	set_target_a2b(t_stack *node, int ref_content)
{
	int	target_content_b;
	int	current;

	target_content_b = get_min_content(node);
	if (target_content_b > ref_content)
		return (get_max_content(node));
	while (node)
	{
		current = get_content(node);
		if ((ref_content - current > 0) && (current > target_content_b))
			target_content_b = current;
		node = node->next;
	}
	return (target_content_b);
}

/*set_target_ba*/
/*
- finds the largest value in the list that is less than a given reference
- Initialize target with the minimum value in the stack
- If all values in the stck are bigger than the reference value
- return the max value
- Traverse the stack to find "the biggest value" > ref content
*/
int	set_target_b2a(t_stack *node, int ref_content)
{
	int	target_content_a;
	int	current;

	target_content_a = get_max_content(node);
	if (target_content_a < ref_content)
		return (get_min_content(node));
	while (node)
	{
		current = get_content(node);
		if ((current - ref_content) > 0 && (current < target_content_a))
			target_content_a = current;
		node = node->next;
	}
	return (target_content_a);
}

/*ft_push_checkb2a*/
/*
- Get the value from the top of stack B
- Determine the target position in stack A
*/
void	push_check_b2a(t_stack **b, t_stack **a)
{
	int	src_content;
	int	target_content;

	src_content = get_content(*b);
	if (src_content > get_max_content(*a) || src_content < get_min_content(*a))
		target_content = get_min_content(*a);
	else
		target_content = set_target_b2a(*a, src_content);
	while (get_content(*a) != target_content)
	{
		if (is_stack_to_rotate(*a, target_content))
			ra(a, 1);
		else
			rra(a, 1);
	}
}

/*sort stack a*/
void	sort_stack_a(t_stack **a)
{
	int	min_content;

	min_content = get_min_content(*a);
	while (get_content(*a) != min_content)
	{
		if (is_stack_to_rotate(*a, min_content))
			ra(a, 1);
		else
			rra(a, 1);
	}
}
