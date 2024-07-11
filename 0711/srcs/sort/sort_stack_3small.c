/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:18 by yilin             #+#    #+#             */
/*   Updated: 2024/07/10 20:39:28 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "libft/includes/libft.h"

/*sort small*/
void	sort_stack_3small(t_stack **stack)
{
	t_stack	*max_node;
	
	max_node = get_max_node(*stack);
	// first is max => ra
	if (*stack == max_node)
		ra(stack);
	// second is max => rra
	else if ((*stack)->next == max_node)
		rra(stack);
	// third(last) is max && first value > second value => sa
	if ((*stack)->content > ((*stack)->next)->content)
		sa(stack);
}

