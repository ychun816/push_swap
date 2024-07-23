/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cheap_a2b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:59:17 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 16:45:33 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ft_target_a2b*/
int	ft_target_a2b(t_stack *node, int ref)
{
	int	target;

	target = get_min_content(node);
	if (ref < target)
		return (get_max_content(node));
	while (node)
	{
		if ((ref - node->content) > 0 && (node->content > target))
			target = node->content;
		node = node->next;
	}
	return (target);
}

/*cal steps a2b*/
int	cal_steps_a2b(t_stack *a, int a_pos, int b_len, t_stack *b)
{
	int	target;
	int	tar_pos;

	target = ft_target_a2b(b, get_content(a));
	tar_pos = get_pos(b, target);
	if (b_len - a_pos > a_pos && ft_stacklen(b) - tar_pos > tar_pos)
		return (ft_bigger(a_pos, tar_pos));
	else if (b_len - a_pos < a_pos && ft_stacklen(b) - tar_pos < tar_pos)
		return (ft_bigger(b_len - a_pos, ft_stacklen(b) - tar_pos));
	else
		return (ft_smaller(a_pos, b_len - a_pos)
			+ ft_smaller(tar_pos, ft_stacklen(b) - tar_pos));
}

/*find_cheapest_a2b*/
int	find_cheapest_a2b(t_stack *a, int a_len, t_stack *b)
{
	t_stack	*tmp;
	int		cheapest;
	int		step;
	int		i;

	tmp = a;
	cheapest = cal_steps_a2b(a, 0, a_len, b);
	i = 0;
	while (i < a_len)
	{
		step = cal_steps_a2b(a, i, a_len, b);
		if (step < cheapest)
		{
			cheapest = step;
			tmp = a;
		}
		i++;
		a = a->next;
	}
	return (tmp->content);
}

/*check_cheap_a2b*/
void	check_cheap_a2b(t_stack **from, int size, t_stack **to, int to_size)
{
	int	cheapest_pos;
	int	tar_pos;

	cheapest_pos = get_pos(*from, find_cheapest_a2b(*from, size, *to));
	tar_pos = get_pos(*to,
			ft_target_a2b(*to, find_cheapest_a2b(*from, size, *to)));
	if (size - cheapest_pos > cheapest_pos && to_size - tar_pos > tar_pos)
		rotate_both(from, to, cheapest_pos, tar_pos);
	else if (size - cheapest_pos < cheapest_pos && to_size - tar_pos < tar_pos)
		rrotate_both(from, to, size - cheapest_pos, to_size - tar_pos);
	else
	{
		if (to_size - tar_pos > tar_pos)
			rb(to, tar_pos);
		else
			rrb(to, to_size - tar_pos);
		if (size - cheapest_pos > cheapest_pos)
			ra(from, cheapest_pos);
		else
			rra(from, size - cheapest_pos);
	}
}
