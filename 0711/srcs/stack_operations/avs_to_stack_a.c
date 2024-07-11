/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avs_to_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:54 by yilin             #+#    #+#             */
/*   Updated: 2024/07/11 17:52:31 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft/includes/libft.h"

/*avs_to_stack_a: (1)ft_atol()*/
int	ft_atol(const char *str)
{
	int	i;
	long	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);	
		i++;
	}
	while (ft_isdigit(str[i]))
		nb = nb * 10 + (str[i++] - 48);
	return (nb * sign);
}

/*avs_to_stack_a: (2-1)append_node- get last node*/

/*avs_to_stack_a: (2-2)append_node- add_new_node*/
t_stack *add_new_node(int content) //t_stack *new_node, int content)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	// new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*avs_to_stack_a: (2-3)append_node*/
static void	append_node(t_stack **stack, int content)
{
	t_stack *new_node;
	t_stack	*last_node;
	
	if (!stack)
		return ;
	new_node = add_new_node(content);
	// if (!new_node)
	// 	return ;
	if (!(*stack))
	{
		*stack = new_node; //if empty =>
		new_node->prev = NULL;
	}
	else  //If the stack is not empty, it means there are existing nodes in the linked list
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node; // Append the new node to the last node
		new_node->prev = last_node;	 // Update the previous pointer of the new node
	}
}

/*avs_to_stack_a: (3)set_stack a*/
void	avs_to_stack_a(t_stack	**stack_a, char **avs)
{
	long	converted_int;
	int	i;

	i = 0;
	while(avs[i])
	{
		if (is_syntax_error(avs[i])) // Check for syntax errors in the argument => if error => exit
			exit_program(NULL, "error: syntax error"); //TODO: //free_errors(a)
		//convert args to long integer
		converted_int = ft_atol((const char *)avs[i]);
		//Check for overflow (value out of int range) INT_MIN & INT MAX => if error=>exit
		if (converted_int < INT_MIN || converted_int > INT_MAX)
			exit_program(NULL, "error: overflow"); //TODO: //free_errors(a)
		//check duplicate =>if error=>exit
		if (is_duplicate_error(*stack_a, (int)converted_int))
			exit_program(NULL, "error: syntax duplicate"); //TODO: //free_errors(a)
		//if no error => append_node
		append_node(stack_a, (int)converted_int);
		i++;
	}
}