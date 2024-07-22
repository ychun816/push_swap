/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:27 by yilin             #+#    #+#             */
/*   Updated: 2024/07/21 19:04:54 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*clear content*/
void	clear(void *content)
{
	free(content);
}

/*clear stack*/
/*
- Temporary pointer to hold the current node.
- Loop through the entire stack
- Save the current node in `tmp`.
- if the next node exits
- set the next node's previous pointer to NULL
- delete the current node
*/
void	clear_stack(t_stack **stack, void (*clear)(void *))
{
	t_stack	*tmp_node;

	while (*stack)
	{
		tmp_node = *stack;
		*stack = (*stack)->next;
		if (*stack)
		{
			(*stack)->prev = NULL;
		}
		clear(tmp_node);
	}
}

/*clear both stacks*/
void	clear_both_stacks(t_stack **a, t_stack **b)
{
	clear_stack(a, &clear);
	clear_stack(b, &clear);
}

/*free strs(frm split)*/
void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}
