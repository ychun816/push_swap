/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilin <yilin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:28:11 by yilin             #+#    #+#             */
/*   Updated: 2024/07/04 11:45:47 by yilin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/includes/libft.h"

//IN LIBFT: ft_isdigit 

/*is stack sorted*/
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

/*is arg within range*/
t_stack	is_arg_in_range(int i, int range, t_stack *a, char *allocated_av[])
{
	int	converted_int;

	converted_int = ft_atol(allocated_av[i], &range);
	if (range == 2)
		exit_program(NULL, "arg not in range");
	ft_stackadd_back(&a, converted_int);
	return (a);
}