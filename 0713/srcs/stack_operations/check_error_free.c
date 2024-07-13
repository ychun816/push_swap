/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:27 by yilin             #+#    #+#             */
/*   Updated: 2024/07/13 21:39:36 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/***is stack sorted***/
bool	is_stack_sorted(t_stack *node)
{
	t_stack	*current;

	current = node;
	if (!node)
		return (true);
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (false);
		current = current->next;
	}
	return (true);
}

/***is syntax error***/
// bool	is_syntax_error(char *str)
// {
// 	if (!str || (!ft_isdigit(*str) && *str != '+' && *str != '-'))
// 		return (true);
// 	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
// 		return (true);
// 	while (*(++str)) 
// 	{
// 		if (!ft_isdigit(*str))
// 			return (true);
// 	}
// 	return (false);
// }
bool	is_syntax_error(char *str)
{
	//Check if the first character of the input string does not contain a sign or a digit
	if (!(*str == '+' || *str == '-' || ft_isdigit(*str)))
		return (true);
	//Check if the first character of the input string contains a sign, but the second character does not contain a digit
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (true);
	//If the error conditions above are passed, 
	//=>pre-increment to point to the next character in the string, 
	//=>and loop until the end of the string is reached
	while (*(++str)) /**str move by one before entering loop */
	{
		if (!ft_isdigit(*str))
			return (true);
	}
	return (false);
}

/***is duplicate error***/
/*use single pointer => check content(value) the pointer points to => use*/
/*if use double pointer => check structure => possibly reallocate memory or update structure*/
bool	is_duplicate_error(t_stack *node, int dup_value)
{
	if (!node)//check if stack NULL
		return (false);
	while (node) //Loop until the end of stack `a` is reached
	{
		if (node->content == dup_value) //Check if the current node's value is equal to `n`. Refer to `init_stack_a()	
			return (true);
		node = node->next;
	}
	return (false);
}
/*word count(frm split)*/
int	ft_wordcount(char const *str, char c)
{
	int	wordlen;
	int	in_word;

	wordlen = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			wordlen++;
		}
		else if (*str == c)
		{
			in_word = 0;
		}
		str++;
	}
	return (wordlen);
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

/*free stack*/
void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!stack || !*stack)/*Check for an empty stack or if stack itself is null*/
		return ;
	current = *stack;/*initialize index*/
	while (current)/*As long as a node exist in the stack*/
	{
		tmp = current->next;/*Assign to `tmp` the pointer to the next node*/
		current->content = 0;/*Clear data to protect sensitive information*/
		free(current);
		current = tmp;/*Assign `tmp` as the current first node*/
	}
	*stack = NULL;/*Set the stack pointer to NULL to indicate it's been freed*/
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
		ft_putstr_fd("Error", 2);/*standard error file descriptor (stderr)*/
		ft_putchar_fd('\n', 2);
	}
	exit(EXIT_FAILURE);
}