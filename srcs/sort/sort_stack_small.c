/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:18 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 16:42:15 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check_pushback_b2a*/
void	check_pushback_b2a(t_stack **b, t_stack **a)
{
	int	top_content;
	int	target;

	top_content = get_content(*b);
	if (top_content > get_max_content(*a) || top_content < get_min_content(*a))
		target = get_min_content(*a);
	else
		target = ft_target_b2a(*a, top_content);
	while (get_content(*a) != target)
	{
		if (is_stack_to_rotate(*a, target))
			ra(a, 1);
		else
			rra(a, 1);
	}
}

/*sort 3*/
void	sort_stack_3nodes(t_stack **a)
{
	int	max_content;

	max_content = get_max_content(*a);
	if (get_content(*a) == max_content)
		ra(a, 1);
	else if (get_content((*a)->next) == max_content)
		rra(a, 1);
	if (get_content(*a) > get_content((*a)->next))
		sa(a);
}

/*sort <5*/
void	sort_stack_small(t_stack **a, t_stack **b, int n_nodes)
{
	if (n_nodes == 2)
		sa(a);
	else if (n_nodes == 3)
		sort_stack_3nodes(a);
	else
	{
		while (n_nodes-- > 3)
		{
			pb(a, b);
		}
		sort_stack_3nodes(a);
		while (*b)
		{
			check_pushback_b2a(b, a);
			pa(a, b);
		}
		sort_stack_a(a);
	}
}
