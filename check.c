/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:11 by yilin             #+#    #+#             */
/*   Updated: 2024/07/03 18:16:30 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//IN LIBFT: ft_isdigit

/*is stack sorted*/
bool	is_stack_sorted(t_stack *stack)
{
	t_stack	*current;
	int	current_content;
	int	next_content;

	i = 0;
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

/*is arg in range*/
t_stack is_arg_in_range(int i, int check_range, t_stack *a, char *allocated_av[])
{
	int	converted_int;

	converted_int = ft_atol(allocated_av[i], &check_range);
	if (check_range == 2)
		exit_program(NULL, "arg not in range");
	ft_stackadd_back(&a, converted_int);
	return (a);
}

/*
t_stack	*check_arg_is_range(int i, int point, t_stack *a, char **converted_argv)
{
	int		converted_int;

	converted_int = ft_atoi(converted_argv[i], &point);
	if (point == 2)
		exit_program(converted_argv, "Arugment is out of range");
	ft_stackadd_back(&a, converted_int);
	return (a);
}
*/