/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:27 by yilin             #+#    #+#             */
/*   Updated: 2024/07/17 18:32:59 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*clear content*/
void	clear_content(void *content)
{
	free(content);
}

/*clear stack*/
void	clear_stack(t_stack **stack, void (*clear_content)(void *))
{
	t_stack *tmp_node; // Temporary pointer to hold the current node.
	
	while (*stack)    // Loop through the entire stack
    {
		tmp_node = *stack;// Save the current node in `tmp`.
        *stack = (*stack)->next;// Move the head pointer to the next node.
		if (clear_content)
			clear_content(tmp_node);
			// clear_content(tmp_node->content);
		free(tmp_node);
    }
}

/*clear both stacks*/
void	clear_both_stacks(t_stack **a, t_stack **b)
{
	clear_stack(a, &clear_content);
	clear_stack(b, &clear_content);
}

/*free strs(frm split)*/
void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}
