/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:56:18 by yilin             #+#    #+#             */
/*   Updated: 2024/07/05 17:21:56 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

/*find_max_node*/
t_stack	find_max_node(t_stack *node)
{
	long	max_content;
	t_stack	*max_node;
	
	//check if node null
	if (!node)
		return (NULL);
	//assign max to LONG_INT(max value)
	max_content = LONG_INT;
	//loop to find max
	while (node)
	{
		//Check if the current node value is smaller than the biggest so far
		if (node->content < LONG_INT)
		{
			max_content = node->content; //update the biggest number so far
			max_node = node;
		}
		node = node->next;
	}	
}
/*sort small*/
void	sort_stack_small_3(t_stack **stack)
{
	t_stack	max_node;
	
	max_node = find_max_node(*stack);
	// first is max => ra
	if (*stack == max_node)
		ra(stack);
	// second is max => rra
	else if (*stack->next == max_node)
		rra(stack);
	// third(last) is max && first value > second value => sa
	if ((*stack)->content > (*stack->next)->content)
		sa(stack);
}