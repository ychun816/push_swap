/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:44:49 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 16:52:39 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*ft_stacklen*/
int	ft_stacklen(t_stack *node)
{
	int	len;

	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

/*ft_stackadd_back*/
/*
- If the new node is NULL, do nothing.
- If the list is empty, set the new node as the head.
- Start from the head of the list.
- Traverse to the last node.
- Set the previous pointer of the new node to the last node.
- Set the next pointer of the last node to the new node.
*/
void	ft_stackadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*tmp_node;

	if (!new_node)
		return ;
	if (!(*stack))
	{
		*stack = new_node;
		return ;
	}
	tmp_node = *stack;
	while (tmp_node->next)
		tmp_node = tmp_node->next;
	new_node->prev = tmp_node;
	tmp_node->next = new_node;
}

/*get content*/
int	get_content(t_stack *node)
{
	if (node == NULL)
		exit(EXIT_FAILURE);
	return (node->content);
}

/*get_max_content*/
/*
- Return the minimum integer value if the list is empty
- Initialize max with the content of the first node
- Check if the current node value is larger than the max so far
- Update the max value so far
*/
int	get_max_content(t_stack *node)
{
	int	max_content;
	int	current_content;

	if (!node)
		return (INT_MIN);
	max_content = node->content;
	while (node)
	{
		current_content = node->content;
		if (current_content > max_content)
			max_content = current_content;
		node = node->next;
	}
	return (max_content);
}

/*get_min_content*/
/*Return the maximum integer value if the list is empty*/
int	get_min_content(t_stack *node)
{
	int	min_content;
	int	current_content;

	if (!node)
		return (INT_MAX);
	min_content = node->content;
	while (node)
	{
		current_content = node->content;
		if (current_content < min_content)
			min_content = current_content;
		node = node->next;
	}
	return (min_content);
}
