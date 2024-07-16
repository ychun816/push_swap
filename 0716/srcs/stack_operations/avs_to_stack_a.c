/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avs_to_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:54 by yilin             #+#    #+#             */
/*   Updated: 2024/07/16 18:53:02 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*clear content*/
/*clear nodes*/
/*avs_to_stack_a(helper): add_new_node*/
t_stack *add_new_node(int content)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->prev = NULL;// Initialize prev to NULL
	new_node->next = NULL;// Initialize next to NULL
	return (new_node);
}

/*avs_to_stack_a(helper):get_last_node*/
/*
head -> [data | next] -> [data | next] -> [data | NULL]
*/
t_stack	*get_last_node(t_stack *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}

/*avs_to_stack_a(helper): append_node*/
static void	append_node(t_stack **stack, int content)
{
	t_stack *new_node;
	t_stack	*last_node;
	
	if (!stack)
		return ;
	new_node = add_new_node(content);
	if (!new_node)
		return ;
	if (!(*stack))
	{
		*stack = new_node;// If stack is empty, new node becomes the head
		new_node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);//If the stack is not empty, it means there are existing nodes in the linked list
		last_node->next = new_node; // Append the new node to the last node
		new_node->prev = last_node;	 // Update the previous pointer of the new node
	}
}

/*avs_to_stack_a(helper):avs_to_stack_a*/
void	avs_to_stack_a(t_stack	**a, int ac, char **av, void (*clear_content)(void *))
{
	int	i;
	int	content;
	t_stack *tmp_node;

	i = 0;
	if (ac != 2)
		i++;
	while (av[i])
	{	
		content = ft_atoi(av[i]);
		tmp_node = add_new_node(content);
		if (!tmp_node)// Check if the stack node was created successfully.
		{
			clear_content(av[i]);//free content that was being processed if the node creation fails.
			clear_stack(a, clear_content);//clears the entire stack if node creation fails.
			return ;
		}
		append_node(a, content);// Add the new node to the stack
		i++;
	}
}

// void	ft_print_all(t_list *lst)
// {
// 	t_list	*tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		ft_printf("lst :%p | val :%d | prev :%14p | next :%14p\n", tmp,
// 			ft_peek(tmp), tmp->prev, tmp->next);
// 		tmp = tmp->next;
// 	}
// }