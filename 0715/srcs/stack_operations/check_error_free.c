/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:27 by yilin             #+#    #+#             */
/*   Updated: 2024/07/15 19:56:41 by yilin            ###   ########.fr       */
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
		ft_printf("Error\n");//write(STDERR_FILENO, "Error\n", 6);
		if (ac == 2)
			free_strs(av);
	}
	exit(0);// exit(EXIT_SUCCESS);
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
// bool	is_stack_sorted(t_stack *node)
// {
// 	t_stack	*current;

// 	current = node;
// 	if (!node)
// 		return (true);
// 	while (current && current->next)
// 	{
// 		if (current->content > current->next->content)
// 			return (false);
// 		current = current->next;
// 	}
// 	return (true);
// }

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

// /*free stack*/
// void	free_stacks(t_stack **stack)
// {
// 	t_stack	*current;
// 	t_stack	*tmp;

// 	if (!stack || !*stack)/*Check for an empty stack or if stack itself is null*/
// 		return ;
// 	current = *stack;/*initialize index*/
// 	while (current)/*As long as a node exist in the stack*/
// 	{
// 		tmp = current->next;/*Assign to `tmp` the pointer to the next node*/
// 		current->content = 0;/*Clear data to protect sensitive information*/
// 		free(current);
// 		current = tmp;/*Assign `tmp` as the current first node*/
// 	}
// 	*stack = NULL;/*Set the stack pointer to NULL to indicate it's been freed*/
// }
// static void	ft_clear_list(t_list **a, t_list **b)
// {
// 	ft_lstclear(a, &ft_del);
// 	ft_lstclear(b, &ft_del);
// }

/*exit program*/
void	exit_program(t_stack **stack, char *error_msg)
{
	// (void)error_msg; // Suppress unused parameter warning for error_msg
	free_stack(stack);
	if (error_msg)
	{
		ft_putstr_fd(error_msg, 2); 
		ft_putchar_fd('\n', 2);
	}
	else
	{
		ft_putstr_fd("Error", 2);/*standard error file descriptor (stderr)*/
		ft_putchar_fd('\n', 2);
	}
	exit(EXIT_FAILURE);
}