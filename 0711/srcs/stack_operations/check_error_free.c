/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:27 by yilin             #+#    #+#             */
/*   Updated: 2024/07/11 19:16:35 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/includes/libft.h"

/*
bool	is_stack_sorted(t_stack *node)
bool	is_syntax_error(char *str)
bool	is_duplicate_error(t_stack	*stack, int content)
void	free_stack(t_stack **stack)
void	exit_program(char	**stack, char *error_msg)
*/

/***is stack sorted***/
bool	is_stack_sorted(t_stack *node)
{
	t_stack	*current;

	current = node;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (false);
		current = current->next;
	}
	return (true);
}
// bool	is_stack_sorted(t_stack *node)
// {
// 	t_stack	*current;
// 	int	current_content;
// 	int	next_content;

// 	current = node; //0
// 	if (!node)
// 		return (true);
// 	if (current->next != NULL)
// 	{
// 		current_content =current->content;
// 		next_content = (current->next)->content;
// 		if (current_content >= next_content)
// 			return (false);
// 		current = current->next;	
// 	}
// 	return (true);
// }

/***is syntax error***/
bool	is_syntax_error(char *str)
{
	if (!str || (!ft_isdigit(*str) && *str != '+' && *str != '-'))
		return (true);
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (true);
	while (*(++str)) 
	{
		if (!ft_isdigit(*str))
			return (true);
	}
	return (false);
}
// bool	is_syntax_error(char *str)
// {
// 	//Check if the first character of the input string does not contain a sign or a digit
// 	if (*str != '+' || *str != '-' || !(ft_isdigit(*str)))
// 		return (true);
// 	//Check if the first character of the input string contains a sign, but the second character does not contain a digit
// 	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
// 		return (true);
// 	//If the error conditions above are passed, 
// 	//=>pre-increment to point to the next character in the string, 
// 	//=>and loop until the end of the string is reached
// 	while (++*str) /**str move by one before entering loop */
// 	{
// 		if (!ft_isdigit(*str))
// 			return (true);
// 	}
// 	return (false);
// }

/***is duplicate error***/
/*use single pointer => check content(value) the pointer points to => use*/
/*if use double pointer => check structure => possibly reallocate memory or update structure*/
bool	is_duplicate_error(t_stack *node, int content)
{
	//check if stack NULL
	if (!node)
		return (false);
	//Loop until the end of stack `a` is reached
		//Check if the current node's value is equal to `n`. Refer to `init_stack_a()	
	while (node)
	{
		if (node->content == content)
			return (true);
		node = node->next;
	}
	return (false);
}

/*free stack*/
void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	current = *stack; /*initialize index*/
	while (current) /*As long as a node exist in the stack*/
	{
		tmp = current->next; /*Assign to `tmp` the pointer to the next node*/
		// current->content = 0; /*Clear data to protect sensitive information*/
		free(current);
		current = tmp; /*Assign `tmp` as the current first node*/
	}
	*stack = NULL;
}

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
		ft_putstr_fd("Error", 2); 
		ft_putchar_fd('\n', 2);
	}
	exit(EXIT_FAILURE);
}
// void	exit_program(t_stack **stack, char *error_msg)
// {
// 	(void)error_msg; // Suppress unused parameter warning for error_msg

// 	free_stack(stack);
// 	ft_putstr_fd(error_msg, 2); 
// 	ft_putchar_fd('\n', 2);
// 	exit(EXIT_FAILURE);
// }