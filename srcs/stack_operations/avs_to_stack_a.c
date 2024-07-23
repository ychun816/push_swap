/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avs_to_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:54 by yilin             #+#    #+#             */
/*   Updated: 2024/07/23 17:04:37 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*clear*/
/*clear stack*/
/*avs_to_stack_a(helper): add_new_node*/
static t_stack	*add_new_node(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*avs_to_stack_a(helper):get_last_node*/
/*
head -> [data | next] -> [data | next] -> [data | NULL]
*/
static t_stack	*get_last_node(t_stack *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}

/*avs_to_stack_a(helper): append_node*/
/*
- If stack is empty, new node becomes the head
- If the stack is not empty, it means there are existing nodes in the linked list
- Append the new node to the last node
- Update the previous pointer of the new node
*/
static void	append_node(t_stack **stack, int content)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!stack)
		return ;
	new_node = add_new_node(content);
	if (!new_node)
		return ;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

/*avs_to_stack_a(helper):avs_to_stack_a*/
/*
- Check if the stack node was created successfully.
- free content that was being processed if the node creation fails.
- clears the entire stack if node creation fails.
- Add the new node to the stack*/
void	avs_to_stack_a(t_stack	**a, int ac, char **split_avs)
		// void (*clear)(void *)
{
	int		i;
	int		content;
	// t_stack	*tmp_node;

	i = 0;
	if (ac != 2)
		i++;
	while (split_avs[i])
	{	
		content = ft_atoi(split_avs[i]);
		// tmp_node = add_new_node(content);
		// if (!tmp_node)
		// {
		// 	clear(split_avs[i]);
		// 	clear_stack(a, clear);
		// 	return ;
		// }
		append_node(a, content);
		i++;
	}
}
