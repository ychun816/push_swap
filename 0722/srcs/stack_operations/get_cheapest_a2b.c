/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest_a2b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:02:51 by yilin             #+#    #+#             */
/*   Updated: 2024/07/22 17:34:57 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Calculate the number of steps required 
 to move a node from one stack to another.
 * 
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
int	count_step_a2b(t_stack *a, int a_pos, int a_len, t_stack *b)
{
	int	trgt_content;
	int	trgt_pos;

	trgt_content = set_target_a2b(b, get_content(a));
	trgt_pos = get_target_position(b, trgt_content);
	if ((a_len - a_pos) > a_pos && (ft_stacklen(b) - trgt_pos) > trgt_pos)
		return (get_pos_bigger(a_pos, trgt_pos));
	else if ((a_len - a_pos) < a_pos && (ft_stacklen(b) - trgt_pos) < trgt_pos)
		return (get_pos_bigger((a_len - a_pos), ft_stacklen(b) - trgt_pos));
	else
		return (get_pos_smaller(a_pos, a_len - a_pos)
			+ get_pos_smaller(trgt_pos, ft_stacklen(b) - trgt_pos));
}

/*set cheapest a2b*/
/*
- Find the cheapest node in stack 'a'
- If no cheapest node is found, exit the function
- Find the target node in stack 'b'
- If no target node is found, exit the function
- Determine the positions of the cheapest node and the target node
- Calculate the cost of rotations
*/

void	set_cheapest_a2b(t_stack **a, int a_len, t_stack **b, int b_len)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = find_cheapest_node(*a);
	if (!cheapest)
		return ;
	target = find_target_node(*b, cheapest->target);
	if (!target)
		return ;
	if ((a_len - (cheapest->pos_ind)) > (cheapest->pos_ind)
		&& b_len - (target->pos_ind) > (target->pos_ind))
		rotate_both(a, b, (cheapest->pos_ind), (target->pos_ind));
	else if (a_len - (cheapest->pos_ind) < (cheapest->pos_ind)
		&& b_len - (target->pos_ind) < (target->pos_ind))
		rrotate_both(a, b, (a_len - cheapest->pos_ind), (b_len - target->pos_ind));
	else
	{
		a2b_rb_or_rrb(b, target->pos_ind, b_len);
		a2b_ra_or_rra(a, cheapest->pos_ind, a_len);
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
/*
- Initialize the temporary pointer to the start of the source stack.
- Calculate the initial cheapest steps for the first node.
- Iterate through the source stack to find the cheapest node to move.
- Update the temporary pointer to the current node
*/
int	get_cheapest_a2b(t_stack *a, int a_len, t_stack *b)
{
	int		cheapest_step;
	int		step;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a;
	cheapest_step = count_step_a2b(a, i, a_len, b);
	while (i < a_len)
	{
		step = count_step_a2b(a, i, a_len, b);
		if (step < cheapest_step)
		{
			cheapest_step = step;
			tmp = a;
		}
		i++;
		a = a->next;
	}
	return (get_content(tmp));
}
