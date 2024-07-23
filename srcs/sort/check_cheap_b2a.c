/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cheap_b2a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:04:01 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 16:47:59 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ft_target_b2a*/
int	ft_target_b2a(t_stack *node, int ref)
{
	int	target;

	target = get_max_content(node);
	if (target < ref)
		return (get_min_content(node));
	while (node)
	{
		if ((get_content(node) - ref) > 0 && (get_content(node) < target))
			target = get_content(node);
		node = node->next;
	}
	return (target);
}

/*cal steps_b2a*/
int	cal_steps_b2a(t_stack *b, int pos, int b_len, t_stack *a)
{
	int	target;
	int	tar_pos;

	target = ft_target_b2a(a, get_content(b));
	tar_pos = get_pos(a, target);
	if (b_len - pos > pos && ft_stacklen(a) - tar_pos > tar_pos)
		return (ft_bigger(pos, tar_pos));
	else if (b_len - pos < pos && ft_stacklen(a) - tar_pos < tar_pos)
		return (ft_bigger(b_len - pos, ft_stacklen(a) - tar_pos));
	else
		return (ft_smaller(pos, b_len - pos)
			+ ft_smaller(tar_pos, ft_stacklen(a) - tar_pos));
}

/*find chepaest_b2a*/
int	find_cheapest_b2a(t_stack *b, int b_len, t_stack *a)
{
	t_stack	*tmp;
	int		cheapest;
	int		step;
	int		i;

	tmp = b;
	cheapest = cal_steps_b2a(b, 0, b_len, a);
	i = 0;
	while (i < b_len)
	{
		step = cal_steps_b2a(b, i, b_len, a);
		if (step < cheapest)
		{
			cheapest = step;
			tmp = b;
		}
		i++;
		b = b->next;
	}
	return (tmp->content);
}

/*check_cheap_b2a*/
void	check_cheap_b2a(t_stack **from, int size, t_stack **to, int to_size)
{
	int	cheapest_pos;
	int	tar_pos;

	cheapest_pos = get_pos(*from, find_cheapest_b2a(*from, size, *to));
	tar_pos = get_pos(*to,
			ft_target_b2a(*to, find_cheapest_b2a(*from, size, *to)));
	if (size - cheapest_pos > cheapest_pos && to_size - tar_pos > tar_pos)
		rotate_both(to, from, tar_pos, cheapest_pos);
	else if (size - cheapest_pos < cheapest_pos && to_size - tar_pos < tar_pos)
		rrotate_both(to, from, to_size - tar_pos, size - cheapest_pos);
	else
	{
		if (to_size - tar_pos > tar_pos)
			ra(to, tar_pos);
		else
			rra(to, to_size - tar_pos);
		if (size - cheapest_pos > cheapest_pos)
			rb(from, cheapest_pos);
		else
			rrb(from, size - cheapest_pos);
	}
}
