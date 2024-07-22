/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:18 by yilin             #+#    #+#             */
/*   Updated: 2024/07/19 18:08:29 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			push_check_b2a(b, a);
			pa(a, b);
		}
		sort_stack_a(a);
	}
}
