/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:44:49 by yilin             #+#    #+#             */
/*   Updated: 2024/07/15 20:03:21 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
/*ft_current_position*/
void	ft_current_position(t_stack *node)
{
	int	current_pos;//To store the index of the current node
	int	median_pos;//To store the position of the median of the stack

	current_pos = 0;
	if (!node)
		return ;
	median_pos = ft_stacklen(node) / 2; //Calculate the median by dividing the length of a stack by 2
	while (node)
	{
		node->position_index = current_pos;//Assign the current index value to the current node
		if (current_pos <= median_pos) //Check whether the current node is above or below the median
			node->above_median = true; //If above, set the above_median data of the node to true
		else
			node->above_median = false;
		node = node->next;
		current_pos++;
	}
}



/*find cheapest_node*/
void	set_cheapest_node(t_stack *node)
{
	long	cheapest_content;
	t_stack	*cheapest_node; 
	
	if (!node)
		return ;
	cheapest_content = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	cheapest_node = NULL;
	while (node)
	{
		if (node->push_cost < cheapest_content)/*Check if current node's push cost CHEAPER than [cheapest content]*/
		{
			cheapest_content = node->push_cost;
			cheapest_node = node;/*Assign the current node as the cheapest node*/
		}
		node = node->next;
	}
	cheapest_node->cheapest = true;/*sets a flag (cuz in structure: boolean cheapest == true=>this node is the "cheapest"*/
}

//get_cheapest_node //
t_stack	*get_cheapest_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node)
	{
		if (node->cheapest)
			return (node);
		node = node->next;
	}
	return (NULL);
}

/*find_max_node*/
t_stack	*get_max_node(t_stack *node)
{
	long	max_content;
	t_stack	*max_node;
	
	//check if node null
	if (!node)
		return (NULL);
	//assign max to LONG_MIN(max value) 
	//=> ensure any content in stack node will be larger than this initial value
	//=>allowing the first node's value to become the new maximum if the list is not empty
	max_content = LONG_MIN;
	max_node = NULL;
	//loop to find max
	while (node)
	{
		//Check if the current node value is smaller than the biggest so far
		if (node->content > max_content)
		{
			max_content = node->content; //update the biggest number so far
			max_node = node;
		}
		node = node->next;
	}
	return (max_node);
}

//find min node
t_stack	*get_min_node(t_stack *node)
{
	long	min_content;
	t_stack	*min_node;
	
	if (!node)
		return (NULL);
	min_content = LONG_MAX;
	min_node = NULL;
	while (node)
	{
		if (node->content < min_content)
		{
			min_content = node->content;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}


// int	ft_max(t_list *lst)
// {
// 	int	max;

// 	max = ft_peek(lst);
// 	while (lst)
// 	{
// 		if (ft_peek(lst) > max)
// 			max = ft_peek(lst);
// 		lst = lst->next;
// 	}
// 	return (max);
// }

// int	ft_min(t_list *lst)
// {
// 	int	min;

// 	min = ft_peek(lst);
// 	while (lst)
// 	{
// 		if (ft_peek(lst) < min)
// 			min = ft_peek(lst);
// 		lst = lst->next;
// 	}
// 	return (min);
// }