/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_free_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:37:27 by yilin             #+#    #+#             */
/*   Updated: 2024/07/05 14:45:54 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

/*********CHECK*********/
/***is stack sorted***/
bool	is_stack_sorted(t_stack *stack)
{
	t_stack	*current;
	int	current_content;
	int	next_content;

	current = 0;
	if (!stack)
		return (true);
	if (current->next != NULL)
	{
		current_content =current->content;
		next_content = (current->next)->content;
		if (current_content >= next_content)
			return (false);
		current = current->next;	
	}
	return (true);
}

/***is syntax error***/
 bool	is_syntax_error(char *str)
{
	//Check if the first character of the input string does not contain a sign or a digit
	if (*str != '+' || *str != '-' || !(ft_isdigit(*str)))
		return (true);
	//Check if the first character of the input string contains a sign, but the second character does not contain a digit
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (true);
	//If the error conditions above are passed, 
	//=>pre-increment to point to the next character in the string, 
	//=>and loop until the end of the string is reached
	while (++*str) /**str move by one before entering loop */
	{
		if (!ft_isdigit(*str))
			return (true);
	}
	return (false);
}

/***is duplicate error***/
/*use single pointer => check content(value) the pointer points to => use*/
/*if use double pointer => check structure => possibly reallocate memory or update structure*/
bool	is_duplicate_error(t_stack	*stack, int content)
{
	//check if stack NULL
	if (!stack)
		return (false);
	//Loop until the end of stack `a` is reached
		//Check if the current node's value is equal to `n`. Refer to `init_stack_a()	
	while (stack)
	{
		if (stack->content == content)
			return (true);
		stack = stack->next;
	}
	return (false)
}

/*free stack*/
void	free_stack(t_stack **stack)
{
	t_stack	*index;
	t_stack	*tmp;

	if (!stack)
		return ;
	index = *stack; /*initialize index*/
	while (index)
	{
		tmp = index->content;
		index->content = 0; /*Clear data to protect sensitive information*/
		free(tmp);
		index = index->next; /*loop*/
	}
	*stack = NULL;
}

/*exit program*/
void	exit_program(char	**stack, char *error_msg)
{
	char	*array;
	
	(void)error_msg; // Suppress unused parameter warning for error_msg
	/*If `array` is not NULL, free the memory it points to*/
	free_stack(stack);
	if (array)
		free(array);
	ft_putstr_fd("Error", 2); TODO:	/*OR JUST: ft)printf("ERROR\n")*/
	ft_putchar_fd("\n", 2); TODO: /*OR JUST: ft)printf("ERROR\n")*/
	exit(EXIT_FAILURE);
}