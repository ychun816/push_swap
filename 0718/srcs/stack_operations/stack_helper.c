/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:44:49 by yilin             #+#    #+#             */
/*   Updated: 2024/07/18 18:06:09 by yilin            ###   ########.fr       */
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
void ft_stackadd_back(t_stack **stack, t_stack *new_node)
{
    t_stack *tmp_node;

    if (!new_node) // If the new node is NULL, do nothing.
        return ;
    if (!(*stack)) // If the list is empty, set the new node as the head.
    {
        *stack = new_node;
        return ;
    }
    tmp_node = *stack; // Start from the head of the list.
    while (tmp_node->next) // Traverse to the last node.
        tmp_node = tmp_node->next;
    new_node->prev = tmp_node; // Set the previous pointer of the new node to the last node.
    tmp_node->next = new_node; // Set the next pointer of the last node to the new node.
}
/*stack deleteone*/
// void ft_stackdelone(t_stack *node, void (*del)(void *))
// {
//     if (!node || !del)
//         return;

//     (*del)(node->content);  // Assuming t_stack has a content field
//     free(node);
// }

/*get content*/
int	get_content(t_stack *node)
{
	//return (ft_atoi((char *)(node->content)));
	if (node ==NULL)
		exit(EXIT_FAILURE);
	return (node->content);
}

/*get_max_content*/
int	get_max_content(t_stack *node)
{
	int	max_content;
	int	current_content;
	
	if (!node)
		return (INT_MIN); //Return the minimum integer value if the list is empty
	max_content = get_content(node);// Initialize max with the content of the first node
	while (node)
	{
		current_content = get_content(node);
		if (current_content > max_content)// Check if the current node value is larger than the max so far
			max_content = current_content;// Update the max value so far
		node = node->next;
	}
	return(max_content);
}

/*get_min_content*/
int	get_min_content(t_stack *node)
{
	int	min_content;
	int	current_content;

	if (!node)
		return (INT_MAX);// Return the maximum integer value if the list is empty
	min_content = get_content(node);
	while (node)
	{
		current_content = get_content(node);
		if (current_content < min_content)
			min_content = current_content;
		node = node->next;	
	}
	return (min_content);
}

/*get target position*/
int	get_target_position(t_stack *node, int target_content)
{
	int	target_position;

	target_position = 0;
	while (node &&  node->content != target_content)
	{
		target_position++;
		node = node->next;
	}
	return (target_position);
}

// [A] FIXME:FIXME:FIXME:
// int	ft_get_loc(t_list *lst, int target)
// {
// 	int	tar_loc;

// 	tar_loc = 0;
// 	while (lst && ft_peek(lst) != target)
// 	{
// 		tar_loc++;
// 		lst = lst->next;
// 	}
// 	return (tar_loc);
// }

// [B] FIXME:FIXME:FIXME:
// void	ft_current_position(t_stack *node)
// {
// 	int	current_pos;//To store the index of the current node
// 	int	median_pos;//To store the position of the median of the stack

// 	current_pos = 0;
// 	if (!node)
// 		return ;
// 	median_pos = ft_stacklen(node) / 2; //Calculate the median by dividing the length of a stack by 2
// 	while (node)
// 	{
// 		node->position_index = current_pos;//Assign the current index value to the current node
// 		if (current_pos <= median_pos) //Check whether the current node is above or below the median
// 			node->above_median = true; //If above, set the above_median data of the node to true
// 		else
// 			node->above_median = false;
// 		node = node->next;
// 		current_pos++;
// 	}
// }

// /*find cheapest_node*/
// void	set_cheapest_node(t_stack *node)
// {
// 	long	cheapest_content;
// 	t_stack	*cheapest_node; 
	
// 	if (!node)
// 		return ;
// 	cheapest_content = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
// 	cheapest_node = NULL;
// 	while (node)
// 	{
// 		if (node->push_cost < cheapest_content)/*Check if current node's push cost CHEAPER than [cheapest content]*/
// 		{
// 			cheapest_content = node->push_cost;
// 			cheapest_node = node;/*Assign the current node as the cheapest node*/
// 		}
// 		node = node->next;
// 	}
// 	cheapest_node->cheapest = true;/*sets a flag (cuz in structure: boolean cheapest == true=>this node is the "cheapest"*/
// }

//get_cheapest_node //
// t_stack	*get_cheapest_node(t_stack *node)
// {
// 	if (!node)
// 		return (NULL);
// 	while (node)
// 	{
// 		if (node->cheapest)
// 			return (node);
// 		node = node->next;
// 	}
// 	return (NULL);
// }
