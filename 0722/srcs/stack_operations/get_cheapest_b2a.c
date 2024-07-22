/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest_b2a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:07:02 by yilin             #+#    #+#             */
/*   Updated: 2024/07/22 17:33:18 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* @param from - The source stack.
* @param loc - The location of the node in the source stack.
* @param size - The size of the source stack.
* @param to - The destination stack.
* @return The number of steps required.
*
- Get the target value in the destination stack for the 'from' node's content.
- Calculate the steps based on the position of the node and target.
- return (ft_bigger(loc, tar_loc)) 
- return (ft_bigger(size - loc, ft_lstsize(to) - tar_loc));
- return (ft_smaller(loc, size - loc) 
+ ft_smaller(tar_loc, ft_lstsize(to) - tar_loc));
*/
int	count_step_b2a(t_stack *b, int b_pos, int b_len, t_stack *a)
{
	int	trgt_pos;
	int	target_content;

	target_content = set_target_b2a(a, get_content(b));
	trgt_pos = get_target_position(a, target_content);
	if ((b_len - b_pos) > b_pos && (ft_stacklen(a) - trgt_pos) > trgt_pos)
		return (get_pos_bigger(b_pos, trgt_pos));
	else if ((b_len - b_pos) < b_pos && (b_len - trgt_pos) < trgt_pos)
		return (get_pos_bigger((b_len - b_pos), ft_stacklen(a) - trgt_pos));
	else
	{
		return (get_pos_smaller(b_pos, b_len - b_pos)
			+ get_pos_smaller(trgt_pos, ft_stacklen(a) - trgt_pos));
	}
}

/*set cheapest b2a*/
/*
- Find the cheapest node in stack 'b'
- If no cheapest node is found, exit the function
- Find the target node in stack 'a'
- If no target node is found, exit the function
- Determine the positions of the cheapest node and the target node
- Calculate the cost of rotations
*/

void	set_cheapest_b2a(t_stack **b, int b_len, t_stack **a, int a_len)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = find_cheapest_node(*b);
	if (!cheapest)
		return ;
	target = find_target_node(*a, cheapest->target);
	if (!target)
		return ;
	if ((b_len - (cheapest->pos_ind)) > (cheapest->pos_ind)
		&& a_len - target->pos_ind > target->pos_ind)
		rotate_both(a, b, cheapest->pos_ind, target->pos_ind);
	else if (b_len - cheapest->pos_ind < cheapest->pos_ind
		&& a_len - target->pos_ind < target->pos_ind)
		rrotate_both(a, b, b_len - cheapest->pos_ind, a_len - target->pos_ind);
	else
	{
		b2a_ra_or_rra(a, target->pos_ind, a_len);
		b2a_rb_or_rrb(b, cheapest->pos_ind, b_len);
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
- Initialize the temporary pointer to the start of the source stack.
- Calculate the initial cheapest steps for the first node.
- Iterate through the source stack to find the cheapest node to move.
- Update the temporary pointer to the current node
*/
int	get_cheapest_b2a(t_stack *b, int b_len, t_stack *a)
{
	int		i;
	int		step;
	int		cheapest_step;
	t_stack	*tmp;

	i = 0;
	tmp = b;
	cheapest_step = count_step_b2a(b, i, b_len, a);
	while (i < b_len)
	{
		step = count_step_b2a(b, i, b_len, a);
		if (step < cheapest_step)
		{
			cheapest_step = step;
			tmp = b;
		}
		i++;
		b = b->next;
	}
	return (get_content(tmp));
}
