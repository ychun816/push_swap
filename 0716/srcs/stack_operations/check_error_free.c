/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:27 by yilin             #+#    #+#             */
/*   Updated: 2024/07/16 20:59:39 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*clear content*/
void	clear_content(void *content)
{
	free(content);
}
/*clear nodes*/
void clear_stack(t_stack **stack, void (*clear_content)(void *))
{
	t_list *tmp_node; // Temporary pointer to hold the current node.
	
	while (*stack)    // Loop through the entire stack
    {
		tmp_node = *stack;// Save the current node in `tmp`.
        *stack = (*stack)->next;// Move the head pointer to the next node.
		if (clear_content)
			clear_content(tmp_node->content);
		free(tmp_node);
    }
}

/*check range*/
int	get_content(t_list *node)
{
	return (ft_atoi((char *)(node->content)));
}

/*check_av_input: (1)check value, (2)check dup*/
/***is value error***/
bool is_value_error(int ac, char **av)
{
	int	i;
	int	nb;
	char *converted_str;
	
	i = 0;
	if (ac != 2)
		i++;// Skip the first argument if not exactly 2 arguments
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		converted_str = ft_itoa(nb);
		// Check if the original string is valid
		// `(!nbr && ft_strcmp(av[i], "0"))` handles the special case of "0"
		// `ft_strcmp(tmp, av[i])` ensures the conversion was exact
		if ((nb == 0 && ft_strcmp(av[i], "0") != 0) || ft_strcmp(converted_str, av[i]) != 0)
		{
			free(converted_str);
			return (true);
		}
		free(converted_str);
		i++;
	}
	return (false);
}
/***is duplicate error***/
bool	is_duplicate_error(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 0;
	if (ac != 2)
		i++;// Skip the first argument if not exactly 2 arguments
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
				return (true);// Duplicate found
			j++;
		}
		i++;
	}
	return (false);//returns "true" if duplicates are found/ no duplicate =>false
}

void check_av_input(int ac, char** av)
{
	if (is_value_error(ac, av) || is_duplicate_error(ac, av))
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (ac == 2)
			free_strs(av);
	}
	exit(EXIT_SUCCESS);
}

/***is stack sorted***/
bool	is_stack_sorted(t_stack *node)
{
	int	ref_content;

	if (!node)
		return (true);
	ref_content = get_content(node);
	while (node->next)
	{
		if (get_content(node->next) < ref_content)//traverse the stack,compare the content of the next node with ref_content
			return (false);// List is not sorted
		ref_content = get_content(node->next);
		node = node->next;
	}
	return (true);// List is sorted
}
/*is stack rotated*/
bool is_stack_to_rotate(t_stack *node, int target_content)
{
	t_stack *tmp_node;
	int	i;
	
	i = 0;
	tmp_node = node;
	while (tmp_node)
	{
		// Check if the current element's value is the target
		if (get_content(tmp_node) == target_content)
			break ;
		i++;
		tmp_node = tmp_node->next;
	}
	// Compare the number of elements before the target (i)
    // elements after the target in the list (ft_lstsize(lst) - i)
	if (i > (ft_stacklen(node) - i))
		return (false);// If it's more efficient to reverse rotate, return 0
	return (true);//Otherwise, return 1 indicating rotation is better
}

/*free strs(frm split)*/
void	free_strs(char **strs, int count)
{
	int	i;

	i = 0;
	if (!strs)
		return;
	while (i < count)
	{
		free((char *)strs[i]);
		i++;
	}
	free((char **)strs);
}
