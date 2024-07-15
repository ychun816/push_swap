/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:18 by yilin             #+#    #+#             */
/*   Updated: 2024/07/15 19:57:57 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3nodes(t_stack **stack_a)
{
	t_stack	*max_node;
	
	max_node = get_max_node(*stack_a);
	if (get_content(*stack_a) == max_node)
		ra(stack_a, 1);
	else if (get_content((*stack_a)->next) == max_node)
		rra(stack_a, 1); //If second is max => reverse rotate the bottom node, to the top of the stack_a?
	if (get_content(*stack_a) > get_content((*stack_a)->next))
		sa(stack_a);
}

void	sort_stack_small(t_stack **a, t_stack **b, int n_nodes)
{
		if (n_nodes == 2)
			sa(a);
		if (n_nodes = 3)
			sort_stack_3nodes(a);
		else
		{
			while (n_nodes-- > 3)
				pb(a, b);
			sort_stack_3nodes(a);
			while (b)
			{
				// ft_push_checkb2a(stk_b, stk_a);
				// ft_pa(stk_b, stk_a);
				prep_node_a(*a, *b);// prep all nodes from both stacks
				push_a_to_b(a, b);
			}
			sort_stack_a(a);
		}
	}
