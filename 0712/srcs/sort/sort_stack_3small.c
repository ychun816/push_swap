/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:18 by yilin             #+#    #+#             */
/*   Updated: 2024/07/12 18:01:54 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3small(t_stack **stack)
{
	t_stack	*max_node;
	
	max_node = get_max_node(*stack);
	if (*stack == max_node)
		ra(stack);
	else if ((*stack)->next == max_node)
		rra(stack); //If second is max => reverse rotate the bottom node, to the top of the stack?
	if ((*stack)->content > ((*stack)->next)->content)
		sa(stack);
}

